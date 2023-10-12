#include <stdlib.h>
#include <stdio.h>
#include <commons/string.h>
#include <commons/log.h>
#include <commons/collections/list.h>
#include "estructura.h"
#include "configuraciones.h"
#include <commons/config.h>

t_config* CONFIGURACIONES;
t_log* LOGGER;
t_filesystem_config* FILESYSTEM_CONFIG;


int main(int argc, char* argv[]) {

    //uso de las log commons
    LOGGER = log_create("./cfg/filesystem.log", "FILESYSTEM", true, LOG_LEVEL_INFO);
    log_info(LOGGER, "Masaje");


    //creado un FCB
    FCB* bloque = fcb_create("Notas1erParcialK9999", 64, 12);
    FCB* bloque2 = fcb_create("textoPrueba",13, 56);
    FCB* bloque3 = fcb_create("quieroMilanga", 46, 51);



    //uso de las listas
    t_list* prueba = list_create();

    list_add(prueba, bloque);
    list_add(prueba, bloque2);
    list_add(prueba, bloque3);


    FCB* variableObt = list_get(prueba, 2);
    log_info(LOGGER, "Metraje un subenir: %s", variableObt->nombre_archivo);
    
    iniciarConfig();


    log_info(LOGGER,"valor ip memoria: %s  valor tamaño bloque: %d", FILESYSTEM_CONFIG->IP_MEMORIA, FILESYSTEM_CONFIG->TAM_BLOQUE);
    log_info(LOGGER,"valor path fcb: %s  valor path fat: %s", FILESYSTEM_CONFIG->PATH_FCB, FILESYSTEM_CONFIG->PATH_FAT);

    return 0;
}


