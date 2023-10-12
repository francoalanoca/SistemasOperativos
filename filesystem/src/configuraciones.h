#ifndef CONFIGURACIONES_H
#define CONFIGURACIONES_H
#include <commons/config.h>
#include <commons/log.h>
#include <stdlib.h>
#include <commons/string.h>


extern t_config* CONFIGURACIONES;
extern t_log* LOGGER;

typedef struct 
{
    char* IP_MEMORIA;
    char* IP_KERNEL;
    char* PUERTO_MEMORIA;
    char* PUERTO_ESCUCHA;
    char* PATH_FAT;
    char* PATH_BLOQUES;
    char* PATH_FCB;
    int CANT_BLOQUES_TOTAL;
    int CANT_BLOQUES_SWAP;
    int TAM_BLOQUE;
    int RETARDO_ACCESO_BLOQUE;
    int RETARDO_ACCESO_FAT;
}t_filesystem_config;


extern t_filesystem_config* FILESYSTEM_CONFIG;

void iniciarConfig();

#endif