#include "memoria.h"

int main(int argc, char* argv[]) {
    //decir_hola("Memoria");

    //Iniciar memoria
    inicializar_memoria();
    log_info(memoria_logger, "Se inicio correctamente Memoria");

    //------------ Conexiones-------------
    iniciar_conexiones();
    log_info(memoria_logger, "Se iniciaron correctamente las conexiones a Memoria");


    //------------ Hilos-------------
    //escuchar_modulos();
    //log_info(memoria_logger, "Se atendio correctamente a los hilos");


    //Finalizar Memoria
    //finalizar_memoria();
    return 0;
}
