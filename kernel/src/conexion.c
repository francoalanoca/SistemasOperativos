#include "conexion.h"

void iniciar_conexiones(){
    //Iniciar server de Kernel
    fd_kernel = iniciar_servidor(PUERTO_CPU_DISPATCH, kernel_logger,"Kernel iniciado");
    log_info(kernel_logger,"Inicio server Kernel exitosamente");

    
    //Conectamos con Cpu como cliente
    fd_cpu_dispatch = crear_conexion(IP_CPU, PUERTO_CPU_DISPATCH);
    log_info(kernel_logger, "Conexion con Cpu - Dispath exitosa");
    fd_cpu_interrupt= crear_conexion(IP_CPU, PUERTO_CPU_INTERRUPT);
    log_info(kernel_logger, "Conexion con Cpu - Interrupt exitosa");
    //Conectamos con Memoria como cliente
    fd_memoria = crear_conexion(IP_MEMORIA, PUERTO_MEMORIA);

    //Esperar al cliente EntradaSalida
    log_info(kernel_logger, "Esperando a Entrada Salida...");
    fd_entradasalida = esperar_cliente(fd_kernel, kernel_logger, "Entrada Salida");
}