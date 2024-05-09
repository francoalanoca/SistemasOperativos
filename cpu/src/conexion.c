#include "conexion.h"

void iniciar_conexiones(){
    
    //Iniciar server de Cpu - Dispatch
    fd_cpu_dispatch = iniciar_servidor(PUERTO_ESCUCHA_DISPATCH, cpu_logger, "Cpu - Dispatch iniciado !!!");
    log_info(cpu_logger,"Inicio server Cpu - Dispatch exitosamente");
    //Iniciar server de Cpu - Interrupt
    fd_cpu_interrupt = iniciar_servidor(PUERTO_ESCUCHA_INTERRUPT, cpu_logger, "Cpu - Interrupt iniciado !!!");
    log_info(cpu_logger,"Inicio server Cpu - Interrupt exitosamente");

    //Conectamos con Memoria como cliente
    fd_memoria = crear_conexion(IP_MEMORIA, PUERTO_MEMORIA);
    log_info(cpu_logger, "Conexion con Memoria exitosa");

    //Esperar al cliente Kernel - Dispatch
    log_info(cpu_logger, "ESperando Kernel - Dispatch");
    fd_kernel_dispatch = esperar_cliente(fd_cpu_dispatch, cpu_logger, "Kernel - Dispatch");
    //Esperar al cliente Kernel - Interrupt
    log_info(cpu_logger, "ESperando Kernel - Interrupt");
    fd_kernel_interrupt = esperar_cliente(fd_cpu_interrupt, cpu_logger, "Kernel - Interrupt");
}