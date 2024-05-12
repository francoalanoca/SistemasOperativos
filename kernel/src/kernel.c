#include "kernel.h"

int main(int argc, char* argv[]) {
    //decir_hola("Kernel");

    //ctrl + f busqueda rapida
    //Iniciar Kernel
    inicializar_kernel();
    log_info(kernel_logger, "Se inicio correctamente Kernel");


    //------------ Conexiones-------------
    iniciar_conexiones();
    log_info(kernel_logger, "Se iniciaron correctamente las conexiones a Kernel");
    

    //------------ Hilos-------------
    //escuchar_modulos();
    log_info(kernel_logger, "Se atendieron correctamente los hilos");


    //------------ Consola-------------
    //Iniciar Consola interactiva
    //Al tener todo lo demas ejectando en hilos podemos usar el principal para la ejecucion de la consola
    iniciar_consola_interactiva();

    //Finalizar Kernel
    //finalizar_kernel();
    return 0;
}

