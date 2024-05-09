#ifndef PROTOCOLO_H_
#define PROTOCOLO_H_

#include <stdio.h>
#include <stdlib.h>

#include <utils/utils.h>
#include <commons/log.h>
#include <commons/config.h>

//#include "cpu.h"

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

void cpu_atender_memoria();
void cpu_atender_kernel_dispatch();
void cpu_atender_kernel_interrupt();

void atender_crear_proceso(t_buffer* un_buffer);
void iterator(char* value);

#endif