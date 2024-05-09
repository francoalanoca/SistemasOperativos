#include <utils/utils.h>

void decir_hola(char* quien) {
    printf("Hola desde %s!!\n", quien);
}



//-----------------------------CLIENTE---------------------------------------

void* serializar_paquete(t_paquete* paquete)
{
	int tamanio_magic = paquete->buffer->size + 2*sizeof(int);
	void * magic = malloc(tamanio_magic);
	int desplazamiento = 0;

	memcpy(magic + desplazamiento, &(paquete->codigo_operacion), sizeof(int));
	desplazamiento+= sizeof(int);
	memcpy(magic + desplazamiento, &(paquete->buffer->size), sizeof(int));
	desplazamiento+= sizeof(int);
	memcpy(magic + desplazamiento, paquete->buffer->stream, paquete->buffer->size);
	desplazamiento+= paquete->buffer->size;

	return magic;
}



int crear_conexion(char *ip, char* puerto)
{
	struct addrinfo hints;
	struct addrinfo *server_info;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(ip, puerto, &hints, &server_info);

	// Ahora vamos a crear el socket.
	//int socket_cliente = 0;
	int socket_cliente = socket(server_info->ai_family,
                         server_info->ai_socktype,
                         server_info->ai_protocol);

	// Ahora que tenemos el socket, vamos a conectarlo
	connect(socket_cliente, server_info->ai_addr, server_info->ai_addrlen);

	freeaddrinfo(server_info);

	return socket_cliente;
}



void enviar_mensaje(char* mensaje, int socket_cliente)
{
	t_paquete* paquete = malloc(sizeof(t_paquete));

	paquete->codigo_operacion = MENSAJE;
	paquete->buffer = malloc(sizeof(t_buffer));
	paquete->buffer->size = strlen(mensaje) + 1;
	paquete->buffer->stream = malloc(paquete->buffer->size);
	memcpy(paquete->buffer->stream, mensaje, paquete->buffer->size);

	int bytes = paquete->buffer->size + 2*sizeof(int);

	void* a_enviar = serializar_paquete(paquete);

	send(socket_cliente, a_enviar, bytes, 0);

	free(a_enviar);
	eliminar_paquete(paquete);
}



t_buffer* crear_buffer()
{
	//Reserbamos memoria para el buffer
	t_buffer* un_buffer = malloc(sizeof(t_buffer));
	//iniciamos su size en 0 y su stream vacio
	un_buffer->size = 0;
	un_buffer->stream = NULL;

	return un_buffer;
}


t_paquete* crear_paquete(op_code cod_op, t_buffer* un_buffer)
{
	t_paquete* paquete = malloc(sizeof(t_paquete));
	paquete->codigo_operacion = PAQUETE;
	paquete->buffer = un_buffer;
	return paquete;
}


//Funciones para la serializacion
//recibe un buffer creado, algo y su tamanio para agregar al buffer
void agregar_a_buffer(t_buffer* un_buffer, void* valor, int tamanio)
{
	//si el buffer esta vacio
	if (un_buffer->size == 0)
	{
		//reservamos memoria para su size y el int
		un_buffer->stream = malloc(sizeof(int) + tamanio);
		//copiamos en el buffer lo que ingreso
		memcpy(un_buffer->stream, &tamanio, sizeof(int));
		//nos desplazamos y copiamos en el buffer el tamanio de lo que ingreso
		memcpy(un_buffer->stream + sizeof(int), valor, tamanio);
	}
	else{ //sino estaba vacio
		//agreandamos el espacio en memoria a lo que necesitemos
		un_buffer->stream = realloc(un_buffer->stream, un_buffer->size + tamanio + sizeof(int));
		//copiamos en el buffer lo que ingreso
		memcpy(un_buffer->stream + un_buffer->size, &tamanio, sizeof(int));
		//nos desplazamos y copiamos en el buffer el tamanio de lo que ingreso
		memcpy(un_buffer->stream + un_buffer->size + sizeof(int), valor, tamanio);
	}
	

	//actualizamos el buffer
	un_buffer->size += sizeof(int);
	un_buffer->size += tamanio;
	//un_buffer->size += tamanio + sizeof(int);
}

//Agrega una variable de tipo int al buffer
void cargar_int_al_buffer(t_buffer* un_buffer, int tamanio_int)
{
	agregar_a_buffer(un_buffer, &tamanio_int, sizeof(int));
}

//Agrega una variable de tipo uint32 al buffer
void cargar_uint32_al_buffer(t_buffer* un_buffer, uint32_t tamanio_uint32)
{
	agregar_a_buffer(un_buffer, &tamanio_uint32, sizeof(uint32_t));
}

//Agrega una variable de tipo string al buffer
void cargar_string_al_buffer(t_buffer* un_buffer, char* tamanio_string)
{
	agregar_a_buffer(un_buffer, tamanio_string, strlen(tamanio_string) + 1);
}


void enviar_paquete(t_paquete* paquete, int socket_cliente)
{
	int bytes = paquete->buffer->size + 2*sizeof(int);
	void* a_enviar = serializar_paquete(paquete);

	send(socket_cliente, a_enviar, bytes, 0);

	free(a_enviar);
}

void eliminar_paquete(t_paquete* paquete)
{
	free(paquete->buffer->stream);
	free(paquete->buffer);
	free(paquete);
}

void eliminar_buffer(t_buffer* un_buffer)
{
	if (un_buffer != NULL)
	{
		free(un_buffer->stream);
	}
	free(un_buffer);
}


void liberar_conexion(int socket_cliente)
{
	close(socket_cliente);
}






//-----------------------------SERVIDOR---------------------------------------

//Se le pasa un puerto donde va estar escuchamdo, su logguer y el mensaje
int iniciar_servidor(char* puerto, t_log* un_logger, char* mensaje_server)
{
	int socket_servidor;

	//Nunca se uso la variable p
	struct addrinfo hints, *servinfo;

	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;

	getaddrinfo(NULL, puerto, &hints, &servinfo);

	//Para estas 3 copie lo que estaba en la guia de sockets y cambie nombre de variables
	// Creamos el socket de escucha del servidor
	socket_servidor = socket(servinfo->ai_family,
                         servinfo->ai_socktype,
                         servinfo->ai_protocol);

	// Asociamos el socket a un puerto
	bind(socket_servidor, servinfo->ai_addr, servinfo->ai_addrlen);
	// Escuchamos las conexiones entrantes
	listen(socket_servidor, SOMAXCONN);

	freeaddrinfo(servinfo);
	log_info(un_logger, "Server: %s", mensaje_server);

	return socket_servidor;
}


int esperar_cliente(int socket_servidor, t_log* un_logger, char* mensaje)
{
	
	// Aceptamos un nuevo cliente
	int socket_cliente = accept(socket_servidor, NULL, NULL);
	log_info(un_logger, "Se conecto el cliente: %s", mensaje);

	return socket_cliente;
}


int recibir_operacion(int socket_cliente)
{
	int cod_op;
	if(recv(socket_cliente, &cod_op, sizeof(int), MSG_WAITALL) > 0)
		return cod_op;
	else
	{
		close(socket_cliente);
		return -1;
	}
}


t_buffer* recibir_buffer(int socket_cliente)
{
	t_buffer * buffer =malloc(sizeof(t_buffer));

	if (recv(socket_cliente, &(buffer->size), sizeof(int), MSG_WAITALL) > 0)
	{
		buffer->stream = malloc(buffer->size);

		if (recv(socket_cliente, buffer->stream, buffer->size, MSG_WAITALL) > 0)
		{
			return buffer;
		}
		else{
			perror("Error al recibir al void* del buffer de la conexion");
			exit(EXIT_FAILURE);
		}
		
	}
	else{
		perror("Error al recibir el tamanio del buffer de la conexion");
			exit(EXIT_FAILURE);
	}
	

	return buffer;
}


void* extraer_contenido_del_buffer(t_buffer* un_buffer)
{
	if (un_buffer->size == 0)
	{
		printf("\n[ERROR] Al intentar extrar contenido de un t_buffer vacio \n\n");
		exit(EXIT_FAILURE);

	}
	
	if (un_buffer->size < 0)
	{
		printf("\n[ERROR] Esto es raro. El t_buffer contiene un size negativo \n\n");
		exit(EXIT_FAILURE);
	}
	
	int tamanio_contenido;
	memcpy(&tamanio_contenido, un_buffer->stream, sizeof(int));
	void* contenido = malloc(tamanio_contenido);
	memcpy(contenido, un_buffer->stream + sizeof(int), tamanio_contenido);

	int nuevo_tamanio = un_buffer->size - sizeof(int) - tamanio_contenido;


	if (nuevo_tamanio == 0)
	{
		un_buffer->size = 0;
		free(un_buffer->stream);
		un_buffer->stream = NULL;
		return contenido;
	}
	
	if (nuevo_tamanio < 0)
	{
		perror("\n[ERROR] Buffer con tamanio negativo");
		exit(EXIT_FAILURE);
	}
	
	void* nuevo_stream = malloc(nuevo_tamanio);
	memcpy(nuevo_stream, un_buffer->stream + sizeof(int) + tamanio_contenido, nuevo_tamanio);
	free(un_buffer->stream);
	un_buffer->size = nuevo_tamanio;
	un_buffer->stream = nuevo_stream;

	return contenido;

}


//Extrae del buffer el valor si es del tipo int
int extraer_int_del_buffer(t_buffer* un_buffer)
{
	int* valor_int = extraer_contenido_del_buffer(un_buffer);
	int valor_retorno = *valor_int;
	free(valor_int);
	return valor_retorno;
}

//Extrae del buffer el valor si es del tipo string
char* extraer_string_del_buffer(t_buffer* un_buffer)
{
	char* valor_string = extraer_contenido_del_buffer(un_buffer);
	return valor_string;
}

//Extrae del buffer el valor si es del tipo uint32
uint32_t extraer_uint32_del_buffer(t_buffer* un_buffer)
{
	uint32_t* valor_uint = extraer_contenido_del_buffer(un_buffer);
	uint32_t valor_retorno = *valor_uint;
	free(valor_uint);
	return valor_retorno;
}


void recibir_mensaje(int socket_cliente)
{
	//int size;
	t_buffer* buffer = recibir_buffer(socket_cliente);
	//log_info(logger, "Me llego un mensaje");
	printf("Me llego un mensaje");
	free(buffer);
}


t_list* recibir_paquete(int socket_cliente)
{
	int size = 0;
	int desplazamiento = 0;
	void * buffer;
	t_list* valores = list_create();
	int tamanio;

	buffer = recibir_buffer(socket_cliente);
	while(desplazamiento < size)
	{
		memcpy(&tamanio, buffer + desplazamiento, sizeof(int));
		desplazamiento+=sizeof(int);
		char* valor = malloc(tamanio);
		memcpy(valor, buffer+desplazamiento, tamanio);
		desplazamiento+=tamanio;
		list_add(valores, valor);
	}
	free(buffer);
	return valores;
}
