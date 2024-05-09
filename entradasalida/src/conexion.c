#include "conexion.h"

void iniciar_conexiones(){
    //Conectamos con Memoria como cliente
    fd_memoria = crear_conexion(IP_MEMORIA, PUERTO_MEMORIA);
    log_info(entradasalida_logger, "Conexion con Memoria exitosa!!!");
    //Conectamos con Kernel como cliente
    fd_kernel = crear_conexion(IP_KERNEL, PUERTO_KERNEL);
    log_info(entradasalida_logger, "Conexion con Kernel exitosa!!!");
}