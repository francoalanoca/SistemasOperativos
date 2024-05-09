#ifndef CONEXION_H_
#define CONEXION_H_

#include <stdio.h>
#include <stdlib.h>

#include <utils/utils.h>
#include <commons/log.h>
#include <commons/config.h>



// ---------Variables Globales---------------

extern t_log* memoria_logger;
extern t_log* memoria_logger_obligatorio;
extern t_config* memoria_config;

extern int fd_memoria;
extern int fd_cpu;
extern int fd_kernel;
extern int fd_entradasalida;

extern char* PUERTO_ESCUCHA;
extern char* TAM_MEMORIA;
extern char* TAM_PAGINA;
extern char* PATH_INSTRUCCIONES;
extern char* RETARDO_RESPUESTA;


void iniciar_conexiones();

#endif