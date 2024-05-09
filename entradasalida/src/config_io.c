#include "config_io.h"

void inicializar_io(){
	inicializar_logs();
    inicializar_config();
}

void inicializar_logs(){
    entradasalida_logger = log_create("entradasalida.log","entradasalida",1, LOG_LEVEL_INFO);
	if(entradasalida_logger == NULL){
		perror("Algo ocurrio al crear el o encontrar el archivo log");
		exit(EXIT_FAILURE);
	}
}

void inicializar_config(){
    entradasalida_config = config_create("./entradasalida.config");
	if(entradasalida_config == NULL){
		perror("Algo ocurrio al crear el archivo config ");
		exit(EXIT_FAILURE);
	}

	TIPO_INTERFAZ = config_get_string_value(entradasalida_config,"TIPO_INTERFAZ");
	TIEMPO_UNIDAD_TRABAJO = config_get_string_value(entradasalida_config,"TIEMPO_UNIDAD_TRABAJO");
	IP_KERNEL = config_get_string_value(entradasalida_config,"IP_KERNEL");
	PUERTO_KERNEL = config_get_string_value(entradasalida_config,"PUERTO_KERNEL");
	IP_MEMORIA = config_get_string_value(entradasalida_config,"IP_MEMORIA");
	PUERTO_MEMORIA = config_get_string_value(entradasalida_config,"PUERTO_MEMORIA");
	PATH_BASE_DIALFS = config_get_string_value(entradasalida_config,"PATH_BASE_DIALFS");
	BLOCK_SIZE = config_get_string_value(entradasalida_config,"BLOCK_SIZE");
	BLOCK_COUNT = config_get_string_value(entradasalida_config,"BLOCK_COUNT");

	log_info(entradasalida_logger, "Este es un ip kernel de prueba: %s ",IP_KERNEL);
}