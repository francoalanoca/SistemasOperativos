#include "protocolo.h"

void escuchar_modulos(){
	//Atender a Kernel
    pthread_t hilo_kernel;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_kernel, NULL, (void*) memoria_atender_kernel, NULL);
    //se desacopla del hilo principal para no interferir
    pthread_detach(hilo_kernel);

    //Atender a Cpu
    pthread_t hilo_cpu;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_cpu, NULL, (void*) memoria_atender_cpu, NULL);
    //se desacopla del hilo principal para no interferir
    pthread_detach(hilo_cpu);

    //Atender a EntradaSalida
    pthread_t hilo_entradasalida;
    //se crea un nuevo hilo que atiende al cliente
    pthread_create(&hilo_entradasalida, NULL, (void*)memoria_atender_io, NULL);
    //caundo el hilo principal llega a join este se detiene hasta que se termine el hilo actual en lugar de deacoplarse
    pthread_join(hilo_entradasalida, NULL);
}


void memoria_atender_cpu(){
    t_list* lista;
    t_buffer* un_buffer;
	while (1) {
        //Se queda esperando a que Cpu le envie algo y extrae el cod de operacion
		int cod_op = recibir_operacion(fd_cpu);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(fd_cpu);
			break;
		case PAQUETE:
			lista = recibir_paquete(fd_cpu);
			log_info(memoria_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_cpu);
            atender_crear_proceso(un_buffer);
            break;
		case -1:
			log_error(memoria_logger, "CPU se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(memoria_logger,"Operacion desconocida de CPU.");
			break;
		}
    }
}

void memoria_atender_kernel(){
    t_list* lista;
    t_buffer* un_buffer;
	while (1) {
        //Se queda esperando a que KErnel le envie algo y extrae el cod de operacion
		int cod_op = recibir_operacion(fd_kernel);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(fd_kernel); 
			break;
		case PAQUETE:
			lista = recibir_paquete(fd_kernel);
			log_info(memoria_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_kernel);
            atender_crear_proceso(un_buffer);
            break;
		case -1:
			log_error(memoria_logger, "Kernel se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(memoria_logger,"Operacion desconocida de Kernel.");
			break;
		}
    }
}

void memoria_atender_io(){
    t_list* lista;
    t_buffer* un_buffer;
	while (1) {
        //Se queda esperando a que IO le envie algo y extrae el cod de operacion
		int cod_op = recibir_operacion(fd_entradasalida);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(fd_entradasalida);
			break;
		case PAQUETE:
			lista = recibir_paquete(fd_entradasalida);
			log_info(memoria_logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
        case CREAR_PROCESO_KERNEL:
            un_buffer = recibir_buffer(fd_entradasalida);
            atender_crear_proceso(un_buffer);
            break;
		case -1:
			log_error(memoria_logger, "Entrada/salida se desconecto. Terminando servidor.");
			//return EXIT_FAILURE;
			break;
		default:
			log_warning(memoria_logger,"Operacion desconocida de Entrada/salida.");
			break;
		}
    }
}





void atender_crear_proceso(t_buffer* un_buffer){
    int pid = extraer_int_del_buffer(un_buffer);
    char* path = extraer_string_del_buffer(un_buffer);
    int size = extraer_int_del_buffer(un_buffer);

    log_info(memoria_logger,"PID: %d, PATH: %s, SIZE: %d", pid, path, size);
    free(path);
}



void iterator(char* value){
	log_info(memoria_logger, "%s", value);
}