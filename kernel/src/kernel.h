#ifndef KERNEL_H_
#define KERNEL_H_

#include <stdlib.h>
#include <stdio.h>

#include <utils/utils.h>
#include <pthread.h>
#include <commons/log.h>
#include <commons/config.h>

#include "config_kernel.h"
#include "conexion.h"
#include "protocolo.h"
#include "consola.h"


t_log* kernel_logger;
t_log* kernel_logger_obligatorio;
t_config* kernel_config;

int fd_kernel;
int fd_memoria;
int fd_cpu_dispatch;
int fd_cpu_interrupt;
int fd_entradasalida;


char* IP_MEMORIA;
char* PUERTO_MEMORIA;
char* IP_CPU;
char* PUERTO_CPU_DISPATCH;
char* PUERTO_CPU_INTERRUPT;
char* ALGORITMO_PLANIFICACION;
char* QUANTUM;
char** RECURSOS;
char** INSTANCIAS_RECURSOS;
char* GRADO_MULTIPROGRAMACION;

int identificador_pid = 1;
int contador_pcbs = 1;
pthread_mutex_t mutex_pid;


int main(int argc, char* argv[]);
void inicializar_kernel(void);


#endif