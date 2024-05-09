#ifndef CONEXION_H_
#define CONEXION_H_

#include <stdio.h>
#include <stdlib.h>

#include <utils/utils.h>
#include <commons/log.h>
#include <commons/config.h>


extern t_log* cpu_logger;
extern t_log* cpu_logger_obligatorio;
extern t_config* cpu_config;

extern int fd_cpu_dispatch;
extern int fd_cpu_interrupt;
extern int fd_kernel_dispatch;
extern int fd_kernel_interrupt;
extern int fd_memoria;

extern char* IP_MEMORIA;
extern char* PUERTO_MEMORIA;
extern char* PUERTO_ESCUCHA_DISPATCH;
extern char* PUERTO_ESCUCHA_INTERRUPT;
extern char* CANTIDAD_ENTRADAS_TLB;
extern char* ALGORITMO_TLB;


void iniciar_conexiones();

#endif