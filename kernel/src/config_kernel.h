#ifndef CONFIG_KERNEL_H_
#define CONFIG_KERNEL_H_

#include <stdio.h>
#include <stdlib.h>

#include <utils/utils.h>
#include <commons/log.h>
#include <commons/config.h>

//NO LLAMAR AL .H MINCIPAL
//#include "kernel.h"

extern t_log* kernel_logger;
extern t_log* kernel_logger_obligatorio;
extern t_config* kernel_config;

extern int fd_kernel;
extern int fd_memoria;
extern int fd_cpu_dispatch;
extern int fd_cpu_interrupt;
extern int fd_entradasalida;


extern char* IP_MEMORIA;
extern char* PUERTO_MEMORIA;
extern char* IP_CPU;
extern char* PUERTO_CPU_DISPATCH;
extern char* PUERTO_CPU_INTERRUPT;
extern char* ALGORITMO_PLANIFICACION;
extern char* QUANTUM;
extern char** RECURSOS;
extern char** INSTANCIAS_RECURSOS;
extern char* GRADO_MULTIPROGRAMACION;

void inicializar_kernel(void);
void inicializar_logs(void);
void inicializar_config(void);

#endif