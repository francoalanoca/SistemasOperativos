#include "cpu.h"

int main(int argc, char* argv[]) {
    //decir_hola("CPU");


    //Iniciar Cpu
    inicializar_cpu();
    log_info(cpu_logger, "Se inicio correctamente Cpu");
    
    //------------ Conexiones-------------
    iniciar_conexiones();
    log_info(cpu_logger, "Se inicio correctamente las conexiones a Cpu");


    //------------ Hilos-------------
    //escuchar_modulos();
    //log_info(cpu_logger, "Se atendio correctamente los hilos")

    //Finalizar Cpu
    //finalizar_cpu();
    return 0;
}

