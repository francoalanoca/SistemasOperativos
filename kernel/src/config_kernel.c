#include "config_kernel.h"

void inicializar_kernel(){
    inicializar_logs();
	inicializar_config();
}

void inicializar_logs(){
    kernel_logger = log_create("kernel.log","kernel",1, LOG_LEVEL_INFO);
	if(kernel_logger == NULL){
		perror("Algo ocurrio al crear el o encontrar el archivo log");
		exit(EXIT_FAILURE);
	}
}


void inicializar_config(){
    kernel_config = config_create("./kernel.config");
	if(kernel_config == NULL){
		perror("Algo ocurrio al crear el archivo config ");
		exit(EXIT_FAILURE);
	}

	IP_MEMORIA = config_get_string_value(kernel_config,"IP_MEMORIA");
	PUERTO_MEMORIA = config_get_string_value(kernel_config,"PUERTO_MEMORIA");
	IP_CPU = config_get_string_value(kernel_config,"IP_CPU");
	PUERTO_CPU_DISPATCH = config_get_string_value(kernel_config,"PUERTO_CPU_DISPATCH");
	PUERTO_CPU_INTERRUPT = config_get_string_value(kernel_config,"PUERTO_CPU_INTERRUPT");
	ALGORITMO_PLANIFICACION = config_get_string_value(kernel_config,"ALGORITMO_PLANIFICACION");
	QUANTUM = config_get_string_value(kernel_config,"QUANTUM");
	RECURSOS = config_get_array_value(kernel_config,"RECURSOS");
	INSTANCIAS_RECURSOS = config_get_array_value(kernel_config,"INSTANCIAS_RECURSOS");
	GRADO_MULTIPROGRAMACION = config_get_string_value(kernel_config,"GRADO_MULTIPROGRAMACION");

	log_info(kernel_logger, "ESte es un ip memoria: %s, Este es un grado de mult: %s ",IP_MEMORIA, GRADO_MULTIPROGRAMACION);


}
