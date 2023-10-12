#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H

#include <stdlib.h>

typedef struct
{
    char* nombre_archivo;
    int tamanio_archivo;
    int bloque_inicial;
}FCB;

FCB* fcb_create(char* ,int ,int );

#endif