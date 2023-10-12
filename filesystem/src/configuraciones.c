#include "configuraciones.h"

void iniciarConfig(){

    //PATH relativo ./ te lleva a la direcion anterior, ../ te lleva 2 direcciones anteriores
    CONFIGURACIONES = config_create("./cfg/filesystem.config"); 

    FILESYSTEM_CONFIG = malloc(sizeof(t_filesystem_config));
    
    FILESYSTEM_CONFIG->IP_MEMORIA = string_new();
    string_append(&FILESYSTEM_CONFIG->IP_MEMORIA, config_get_string_value(CONFIGURACIONES, "IP_MEMORIA"));
    FILESYSTEM_CONFIG->IP_KERNEL = string_new();
    string_append(&FILESYSTEM_CONFIG->IP_KERNEL, config_get_string_value(CONFIGURACIONES, "IP_KERNEL"));
    FILESYSTEM_CONFIG->PUERTO_MEMORIA = string_new();
    string_append(&FILESYSTEM_CONFIG->PUERTO_MEMORIA, config_get_string_value(CONFIGURACIONES, "PUERTO_MEMORIA"));
    FILESYSTEM_CONFIG->PUERTO_ESCUCHA = string_new();
    string_append(&FILESYSTEM_CONFIG->PUERTO_ESCUCHA, config_get_string_value(CONFIGURACIONES, "PUERTO_ESCUCHA"));
    FILESYSTEM_CONFIG->PATH_FAT = string_new();
    string_append(&FILESYSTEM_CONFIG->PATH_FAT, config_get_string_value(CONFIGURACIONES, "PATH_FAT"));
    FILESYSTEM_CONFIG->PATH_BLOQUES = string_new();
    string_append(&FILESYSTEM_CONFIG->PATH_BLOQUES, config_get_string_value(CONFIGURACIONES, "PATH_BLOQUES"));
    FILESYSTEM_CONFIG->PATH_FCB = string_new();
    string_append(&FILESYSTEM_CONFIG->PATH_FCB, config_get_string_value(CONFIGURACIONES, "PATH_FCB"));
    FILESYSTEM_CONFIG->CANT_BLOQUES_TOTAL = config_get_int_value(CONFIGURACIONES, "CANT_BLOQUES_TOTAL");
    FILESYSTEM_CONFIG->CANT_BLOQUES_SWAP = config_get_int_value(CONFIGURACIONES, "CANT_BLOQUES_SWAP");
    FILESYSTEM_CONFIG->TAM_BLOQUE = config_get_int_value(CONFIGURACIONES, "TAM_BLOQUE");
    FILESYSTEM_CONFIG->RETARDO_ACCESO_BLOQUE = config_get_int_value(CONFIGURACIONES, "RETARDO_ACCESO_BLOQUE");
    FILESYSTEM_CONFIG->RETARDO_ACCESO_FAT = config_get_int_value(CONFIGURACIONES, "RETARDO_ACCESO_FAT");
    
    /*1er Metorodo - Posible error en las asignaciones de memoria del char*
    FILESYSTEM_CONFIG->IP_MEMORIA = config_get_string_value(CONFIGURACIONES, "IP_MEMORIA");
    FILESYSTEM_CONFIG->IP_KERNEL = config_get_string_value(CONFIGURACIONES, "IP_KERNEL");
    FILESYSTEM_CONFIG->PUERTO_MEMORIA = config_get_string_value(CONFIGURACIONES, "PUERTO_MEMORIA");
    FILESYSTEM_CONFIG->PUERTO_ESCUCHA = config_get_string_value(CONFIGURACIONES, "PUERTO_ESCUCHA");
    FILESYSTEM_CONFIG->PATH_FAT = config_get_string_value(CONFIGURACIONES, "PATH_FAT");
    FILESYSTEM_CONFIG->PATH_BLOQUES = config_get_string_value(CONFIGURACIONES, "PATH_BLOQUES");
    FILESYSTEM_CONFIG->PATH_FCB = config_get_string_value(CONFIGURACIONES, "PATH_FCB");
    FILESYSTEM_CONFIG->CANT_BLOQUES_TOTAL = config_get_int_value(CONFIGURACIONES, "CANT_BLOQUES_TOTAL");
    FILESYSTEM_CONFIG->CANT_BLOQUES_SWAP = config_get_int_value(CONFIGURACIONES, "CANT_BLOQUES_SWAP");
    FILESYSTEM_CONFIG->TAM_BLOQUE = config_get_int_value(CONFIGURACIONES, "TAM_BLOQUE");
    FILESYSTEM_CONFIG->RETARDO_ACCESO_BLOQUE = config_get_int_value(CONFIGURACIONES, "RETARDO_ACCESO_BLOQUE");
    FILESYSTEM_CONFIG->RETARDO_ACCESO_FAT = config_get_int_value(CONFIGURACIONES, "RETARDO_ACCESO_FAT");
    */
log_info(LOGGER,"Me traje todos datos de config");
}

