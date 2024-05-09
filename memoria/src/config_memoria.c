#include "config_memoria.h"

void inicializar_memoria(){
    inicializar_logs();
    inicializar_config();
}

void inicializar_logs(){
    memoria_logger = log_create("memoria.log","memoria",1, LOG_LEVEL_INFO);
	if(memoria_logger == NULL){
		perror("Algo ocurrio al crear el o encontrar el archivo log");
		exit(EXIT_FAILURE);
	}
}

void inicializar_config(){
    memoria_config = config_create("./memoria.config");
	if(memoria_config == NULL){
		perror("Algo ocurrio al crear el archivo config ");
		exit(EXIT_FAILURE);
	}

	PUERTO_ESCUCHA = config_get_string_value(memoria_config, "PUERTO_ESCUCHA");
	TAM_MEMORIA = config_get_string_value(memoria_config, "TAM_MEMORIA");
	TAM_PAGINA = config_get_string_value(memoria_config,"TAM_PAGINA");
	PATH_INSTRUCCIONES = config_get_string_value(memoria_config,"PATH_INSTRUCCIONES");
	RETARDO_RESPUESTA = config_get_string_value(memoria_config,"RETARDO_RESPUESTA");

	log_info(memoria_logger,"PUERTO_ESCUCHA: %s", PUERTO_ESCUCHA);
}