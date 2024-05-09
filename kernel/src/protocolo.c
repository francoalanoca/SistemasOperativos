#include "protocolo.h"



//A partir de aca es una implementacion basica orientada a los checkpoin siguientes.
//Protocolo de comunicacion: va a ser a traves de las funciones de atender_a_Modulo, donde
//segun el codigo de operacion que reciba se realizaran los distintos casos a manejar.

void escuchar_modulos(){
    //Atender a EntradaSalida
    pthread_t hilo_entradasalida;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_entradasalida, NULL, (void*)kernel_atender_io, NULL);
    //se desacopla del hilo principal para no interferir
    pthread_detach(hilo_entradasalida);

    //Atender a Cpu - Dispatch
    pthread_t hilo_cpu_dispatch;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_cpu_dispatch, NULL, (void*)kernel_atender_cpu_dispatch, NULL);
    //se desacopla del hilo principal para no interferir
    pthread_detach(hilo_cpu_dispatch);

    //Atender a Cpu - Interrupt
    pthread_t hilo_cpu_interrupt;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_cpu_interrupt, NULL, (void*)kernel_atender_cpu_interrupt, NULL);
    //se desacopla del hilo principal para no interferir
    pthread_detach(hilo_cpu_interrupt);

    //Atender a Memoria
    pthread_t hilo_memoria;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_memoria, NULL, (void*)kernel_atender_memoria, NULL);
    //caundo el hilo principal llega a join este se detiene hasta que se termine el hilo actual en lugar de deacoplarse
    pthread_join(hilo_memoria, NULL);
}




void kernel_atender_cpu_dispatch(){
    t_list* lista;
    t_buffer* un_buffer;
	while (1) {
		int cod_op = recibir_operacion(fd_cpu_dispatch);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(fd_cpu_dispatch); 
			break;
		case PAQUETE:
			lista = recibir_paquete(fd_cpu_dispatch);
			log_info(kernel_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_cpu_dispatch);
            atender_crear_proceso(un_buffer);
            break;
		case -1:
			log_error(kernel_logger, "CPU Dispatch se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(kernel_logger,"Operacion desconocida de CPU Dispatch.");
			break;
		}
    }
}

void kernel_atender_cpu_interrupt(){
    t_list* lista;
    t_buffer* un_buffer;
	while (1) {
		int cod_op = recibir_operacion(fd_cpu_interrupt);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(fd_cpu_interrupt); 
			break;
		case PAQUETE:
			lista = recibir_paquete(fd_cpu_interrupt);
			log_info(kernel_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_cpu_interrupt);
            atender_crear_proceso(un_buffer);
            break;
		case -1:
			log_error(kernel_logger, "CPU Interrupt se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(kernel_logger,"Operacion desconocida de CPU Interrupt.");
			break;
		}
    }
}

void kernel_atender_io(){
    t_list* lista;
    t_buffer* un_buffer;
	while (1) {
		int cod_op = recibir_operacion(fd_entradasalida);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(fd_entradasalida); 
			break;
		case PAQUETE:
			lista = recibir_paquete(fd_entradasalida);
			log_info(kernel_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_entradasalida);
            atender_crear_proceso(un_buffer);
            break;
		case -1:
			log_error(kernel_logger, "Entrada/salida se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(kernel_logger,"Operacion desconocida de Entrada/salida.");
			break;
		}
    }
}

void kernel_atender_memoria(){
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
			log_info(kernel_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_memoria);
            atender_crear_proceso(un_buffer);
            break;
		case -1:
			log_error(kernel_logger, "Memoria se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(kernel_logger,"Operacion desconocida de Memoria.");
			break;
		}
    }
}

void atender_crear_proceso(t_buffer* un_buffer){
    int pid = extraer_int_del_buffer(un_buffer);
    char* path = extraer_string_del_buffer(un_buffer);
    int size = extraer_int_del_buffer(un_buffer);

    log_info(kernel_logger,"PID: %d, PATH: %s, SIZE: %d", pid, path, size);
    free(path);
}




void iterator(char* value){
	log_info(kernel_logger, "%s", value);
}