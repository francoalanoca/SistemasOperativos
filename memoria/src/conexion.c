#include "conexion.h"

void iniciar_conexiones(){
    //Iniciar server de Memoria
    fd_memoria = iniciar_servidor(PUERTO_ESCUCHA, memoria_logger, "Memoria iniciada!!!");
    log_info(memoria_logger,"Inicio de server Kernel exitosamente");

    //Esperar al cliente Kernel
    log_info(memoria_logger, "Conexion con Kernel exitosa");
    fd_kernel = esperar_cliente(fd_memoria, memoria_logger, "Kernel");
    //Esperar al cliente Cpu
    log_info(memoria_logger, "Conexion con Cpu exitosa");
    fd_cpu = esperar_cliente(fd_memoria,memoria_logger, "Cpu");
    //Esperar al cliente EntradaSalida
    log_info(memoria_logger, "Conexion con Entrada Salida exitosa");
    fd_entradasalida = esperar_cliente(fd_memoria, memoria_logger, "Entrada Salida");
}