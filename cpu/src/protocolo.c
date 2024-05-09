#include "protocolo.h"


//A partir de aca es una implementacion basica orientada a los checkpoin siguientes.
//Protocolo de comunicacion: va a ser a traves de las funciones de atender_a_Modulo, donde
//segun el codigo de operacion que reciba se realizaran los distintos casos a manejar.

void escuchar_modulos(){

	//Atender a Memoria
    pthread_t hilo_memoria;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_memoria, NULL, (void*)cpu_atender_memoria, NULL);
    //se desacopla del hilo principal para no interferir
    pthread_detach(hilo_memoria);

    //Atender a Kernel - Dispatch
    pthread_t hilo_kernel_dispatch;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_kernel_dispatch, NULL, (void*)cpu_atender_kernel_dispatch, NULL);
    //se desacopla del hilo principal para no interferir
    pthread_detach(hilo_kernel_dispatch);

    //Atender a Kernel - Interrupt
    pthread_t hilo_kernel_interrupt;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_kernel_interrupt, NULL, (void*)cpu_atender_kernel_interrupt, NULL);
    //caundo el hilo principal llega a join este se detiene hasta que se termine el hilo actual en lugar de deacoplarse
    pthread_join(hilo_kernel_interrupt, NULL);
}


void cpu_atender_memoria(){
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
			log_info(cpu_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_memoria);
            atender_crear_proceso(un_buffer);
            break;
		case -1:
			log_error(cpu_logger, "Memoria se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(cpu_logger,"Operacion desconocida de Memoria.");
			break;
		}
    }
}

void cpu_atender_kernel_dispatch(){
    t_list* lista;
    t_buffer* un_buffer;
	while (1) {
		int cod_op = recibir_operacion(fd_kernel_dispatch);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(fd_kernel_dispatch); 
			break;
		case PAQUETE:
			lista = recibir_paquete(fd_kernel_dispatch);
			log_info(cpu_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_kernel_dispatch);
            atender_crear_proceso(un_buffer);
            break;
		case -1:
			log_error(cpu_logger, "Kernel Dispacth se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(cpu_logger,"Operacion desconocida de Kernel Dispatch.");
			break;
		}
    }
}

void cpu_atender_kernel_interrupt(){
    t_list* lista;
    t_buffer* un_buffer;
	while (1) {
		int cod_op = recibir_operacion(fd_kernel_interrupt);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(fd_kernel_interrupt); 
			break;
		case PAQUETE:
			lista = recibir_paquete(fd_kernel_interrupt);
			log_info(cpu_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_kernel_interrupt);
            atender_crear_proceso(un_buffer);
            break;
		case -1:
			log_error(cpu_logger, "Kernel Interrupt se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(cpu_logger,"Operacion desconocida de Kernel Interrupt.");
			break;
		}
    }
}

void atender_crear_proceso(t_buffer* un_buffer){
    int pid = extraer_int_del_buffer(un_buffer);
    char* path = extraer_string_del_buffer(un_buffer);
    int size = extraer_int_del_buffer(un_buffer);

    log_info(cpu_logger,"PID: %d, PATH: %s, SIZE: %d", pid, path, size);
    free(path);
}


void iterator(char* value){
	log_info(cpu_logger, "%s", value);
}