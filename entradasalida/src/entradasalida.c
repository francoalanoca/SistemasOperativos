#include "entradasalida.h"

int main(int argc, char* argv[]) {
    //decir_hola("una Interfaz de Entrada/Salida");

    //Iniciar EntradaSalida
    inicializar_io();
    log_info(entradasalida_logger, "Se inicio correctamente Entrada Salida");
    

    //------------ Conexiones-------------
    iniciar_conexiones();
    log_info(entradasalida_logger, "Se inicio correctamente las conexiones a IO");
    

    //------------ Hilos-------------
    //escuchar_modulos();
    //log_info(entradasalida_logger, "Se atendio correctamente a los hilos");

    //Finalizar EntradaSalida
    //finalizar_entradasalida();
    return 0;
}


