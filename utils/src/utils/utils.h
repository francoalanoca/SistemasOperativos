#ifndef UTILS_H_
#define UTILS_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#include<signal.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netdb.h>
#include<string.h>

#include<commons/log.h>
#include<commons/collections/list.h>
#include<assert.h>
#include<commons/config.h> 

/**
* @fn    decir_hola
* @brief Imprime un saludo al nombre que se pase por parámetro por consola.
*/
void decir_hola(char* quien);

//-------------Structs de Cliente--------------------
typedef enum
{
	MENSAJE,
	PAQUETE,
    CREAR_PROCESO_KERNEL
    //------Kernel-Memoria---------
    //------Kernel-Cpu---------
    //------Kernel-I/O---------
    //------Cpu-Memoria---------
}op_code;

//Structs para envio/recibo paquetes
typedef struct
{
	int size;
	void* stream;
} t_buffer;

typedef struct
{
	op_code codigo_operacion;
	t_buffer* buffer;
} t_paquete;

extern t_log* logger;


//-------------Funciones de Cliente--------------------
void* serializar_paquete(t_paquete* paquete);
int crear_conexion(char *ip, char* puerto);
void enviar_mensaje(char* mensaje, int socket_cliente);
t_buffer* crear_buffer();
t_paquete* crear_paquete(op_code cod_op, t_buffer* un_buffer);
void agregar_a_buffer(t_buffer* un_buffer, void* valor, int tamanio);
void cargar_int_al_buffer(t_buffer* un_buffer, int tamanio_int);
void cargar_uint32_al_buffer(t_buffer* un_buffer, uint32_t tamanio_uint32);
void cargar_string_al_buffer(t_buffer* un_buffer, char* tamanio_string);
void enviar_paquete(t_paquete* paquete, int socket_cliente);
void eliminar_paquete(t_paquete* paquete);
void eliminar_buffer(t_buffer* un_buffer);
void liberar_conexion(int socket_cliente);

//-------------Funciones de Server--------------------
int iniciar_servidor(char* puerto, t_log* un_logger, char* mensaje_server);
int esperar_cliente(int socket_servidor, t_log* un_logger, char* mensaje);
int recibir_operacion(int socket_cliente);
t_buffer* recibir_buffer(int socket_cliente);
void* extraer_contenido_del_buffer(t_buffer* un_buffer);
int extraer_int_del_buffer(t_buffer* un_buffer);
char* extraer_string_del_buffer(t_buffer* un_buffer);
uint32_t extraer_uint32_del_buffer(t_buffer* un_buffer);
void recibir_mensaje(int socket_cliente);
t_list* recibir_paquete(int socket_cliente);


#endif