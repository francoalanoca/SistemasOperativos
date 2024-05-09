#ifndef ENTRADASALIDA_H_
#define ENTRADASALIDA_H_

#include <stdio.h>
#include <stdlib.h>

#include <utils/utils.h>
#include <pthread.h>
#include <commons/log.h>
#include <commons/config.h>

#include "config_io.h"
#include "conexion.h"
#include "protocolo.h"

t_log* entradasalida_logger;
t_log* entradasalida_logger_obligatorio;
t_config* entradasalida_config;

int fd_entradasalida;
int fd_kernel;
int fd_memoria;

char* TIPO_INTERFAZ;
char* TIEMPO_UNIDAD_TRABAJO;
char* IP_KERNEL;
char* PUERTO_KERNEL;
char* IP_MEMORIA;
char* PUERTO_MEMORIA;
char* PATH_BASE_DIALFS;
char* BLOCK_SIZE;
char* BLOCK_COUNT;


#endif