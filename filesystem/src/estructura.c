#include "estructura.h"


FCB* fcb_create(char* nombre ,int varA ,int varB){
    FCB* fcb_creado = (FCB*) malloc(sizeof(FCB));
    
    fcb_creado->nombre_archivo = nombre;
    fcb_creado->tamanio_archivo = varA;
    fcb_creado->bloque_inicial = varB;

    return fcb_creado;
}