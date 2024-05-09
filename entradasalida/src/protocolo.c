#include "protocolo.h"



//A partir de aca es una implementacion basica orientada a los checkpoin siguientes.
//Protocolo de comunicacion: va a ser a traves de las funciones de atender_a_Modulo, donde
//segun el codigo de operacion que reciba se realizaran los distintos casos a manejar.

void escuchar_modulos(){
    //Atender a Kernel
    pthread_t hilo_kernel;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_kernel, NULL, (void*)io_atender_kernel, NULL);
    //se desacopla del hilo principal para no interferir
    pthread_detach(hilo_kernel);

    //Atender a Memoria
    pthread_t hilo_memoria;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_memoria, NULL, (void*)io_atender_memoria, NULL);
    //se desacopla del hilo principal para no interferir
    pthread_join(hilo_memoria, NULL);
}



void io_atender_kernel(){
    t_list* lista;
    t_buffer* un_buffer;
	while (1) {
		int cod_op = recibir_operacion(fd_kernel);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(fd_kernel); 
			break;
		case PAQUETE:
			lista = recibir_paquete(fd_kernel);
			log_info(entradasalida_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_kernel);
            atender_crear_preceso(un_buffer);
            break;
		case -1:
			log_error(entradasalida_logger, "Kernel se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(entradasalida_logger,"Operacion desconocida de Kernel.");
			break;
		}
    }
}

void io_atender_memoria(){
    t_list* lista;
    t_buffer* un_buffer;
	while (1) {
		int cod_op = recibir_operacion(fd_memoria);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(fd_memoria); 
			break;
		case PAQUETE:
			lista = recibir_paquete(fd_memoria);
			log_info(entradasalida_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_memoria);
            atender_crear_preceso(un_buffer);
            break;
		case -1:
			log_error(entradasalida_logger, "Memoria se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(entradasalida_logger,"Operacion desconocida de Memoria.");
			break;
		}
    }
}

void atender_crear_preceso(t_buffer* un_buffer){
    int pid = extraer_int_del_buffer(un_buffer);
    char* path = extraer_string_del_buffer(un_buffer);
    int size = extraer_int_del_buffer(un_buffer);

    log_info(entradasalida_logger,"PID: %d, PATH: %s, SIZE: %d", pid, path, size);
    free(path);
}


void iterator(char* value){
	log_info(entradasalida_logger, "%s", value);
}
