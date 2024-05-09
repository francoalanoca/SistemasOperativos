#ifndef MEMORIA_H_
#define MEMORIA_H_

#include <stdio.h>
#include <stdlib.h>

#include <utils/utils.h>
#include <pthread.h>
#include <commons/log.h>
#include <commons/config.h>

#include "config_memoria.h"
#include "protocolo.h"
#include "conexion.h"

t_log* memoria_logger;
t_log* memoria_logger_obligatorio;
t_config* memoria_config;

int fd_memoria;
int fd_cpu;
int fd_kernel;
int fd_entradasalida;

char* PUERTO_ESCUCHA;
char* TAM_MEMORIA;
char* TAM_PAGINA;
char* PATH_INSTRUCCIONES;
char* RETARDO_RESPUESTA;



#endif