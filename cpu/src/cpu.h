#ifndef CPU_H_
#define CPU_H_

#include <stdio.h>
#include <stdlib.h>

#include <utils/utils.h>
#include <pthread.h>
#include <commons/log.h>
#include <commons/config.h>

#include "config_cpu.h"
#include "protocolo.h"
#include "conexion.h"

t_log* cpu_logger;
t_log* cpu_logger_obligatorio;
t_config* cpu_config;

int fd_cpu_dispatch;
int fd_cpu_interrupt;
int fd_kernel_dispatch;
int fd_kernel_interrupt;
int fd_memoria;

char* IP_MEMORIA;
char* PUERTO_MEMORIA;
char* PUERTO_ESCUCHA_DISPATCH;
char* PUERTO_ESCUCHA_INTERRUPT;
char* CANTIDAD_ENTRADAS_TLB;
char* ALGORITMO_TLB;


void escuchar_modulos();

#endif