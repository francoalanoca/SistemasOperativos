#include "config_cpu.h"

void inicializar_cpu(){
    inicializar_logs();
    inicializar_config();
}

void inicializar_logs(){
    cpu_logger = log_create("cpu.log","cpu",1, LOG_LEVEL_INFO);
	if(cpu_logger == NULL){
		perror("Algo ocurrio al crear el o encontrar el archivo log");
		exit(EXIT_FAILURE);
	}
}

void inicializar_config(){
    cpu_config = config_create("./cpu.config");
	if(cpu_config == NULL){
		perror("Algo ocurrio al crear el archivo config ");
		exit(EXIT_FAILURE);
	}


	IP_MEMORIA = config_get_string_value(cpu_config,"IP_MEMORIA");
	PUERTO_MEMORIA = config_get_string_value(cpu_config,"PUERTO_MEMORIA");
	PUERTO_ESCUCHA_DISPATCH = config_get_string_value(cpu_config,"PUERTO_ESCUCHA_DISPATCH");
	PUERTO_ESCUCHA_INTERRUPT = config_get_string_value(cpu_config,"PUERTO_ESCUCHA_INTERRUPT");
	CANTIDAD_ENTRADAS_TLB = config_get_string_value(cpu_config,"CANTIDAD_ENTRADAS_TLB");
	ALGORITMO_TLB = config_get_string_value(cpu_config,"ALGORITMO_TLB");

}