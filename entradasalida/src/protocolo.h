#ifndef PROTOCOLO_H_
#define PROTOCOLO_H_

#include <stdio.h>
#include <stdlib.h>

#include <utils/utils.h>
#include <commons/log.h>
#include <commons/config.h>


extern t_log* entradasalida_logger;
extern t_log* entradasalida_logger_obligatorio;
extern t_config* entradasalida_config;

extern int fd_entradasalida;
extern int fd_kernel;
extern int fd_memoria;

extern char* TIPO_INTERFAZ;
extern char* TIEMPO_UNIDAD_TRABAJO;
extern char* IP_KERNEL;
extern char* PUERTO_KERNEL;
extern char* IP_MEMORIA;
extern char* PUERTO_MEMORIA;
extern char* PATH_BASE_DIALFS;
extern char* BLOCK_SIZE;
extern char* BLOCK_COUNT;


void escuchar_modulos();
void iterator(char*);
void io_atender_kernel();
void io_atender_memoria();
void atender_crear_preceso(t_buffer*);

#endif