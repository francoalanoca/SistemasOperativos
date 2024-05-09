#ifndef PROTOCOLO_H_
#define PROTOCOLO_H_

#include <stdio.h>
#include <stdlib.h>

#include <utils/utils.h>
#include <commons/log.h>
#include <commons/config.h>


extern t_log* kernel_logger;
extern t_log* kernel_logger_obligatorio;
extern t_config* kernel_config;

extern int fd_kernel;
extern int fd_memoria;
extern int fd_cpu_dispatch;
extern int fd_cpu_interrupt;
extern int fd_entradasalida;


void escuchar_modulos();
void iterator(char*);
void kernel_atender_cpu_dispatch();
void kernel_atender_cpu_interrupt();
void kernel_atender_io();
void kernel_atender_memoria();
void atender_crear_proceso(t_buffer*);

#endif