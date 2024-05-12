#ifndef CONSOLA_H_
#define CONSOLA_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <readline/readline.h>

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

extern int identificador_pid;
extern int contador_pcbs;
extern pthread_mutex_t mutex_pid;

void iniciar_consola_interactiva();

#endif