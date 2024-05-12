#include "consola.h"

void iniciar_consola_interactiva(){

    char* leido;
    //Asignamos el caracter > a la variable leido
	leido = readline("> ");
	log_info(logger, leido);
    bool validacion_leido;

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío
	while (strcmp(leido, "\0") != 0){

        validacion_leido = validacion_de_instruccion_de_consola(leido);
        if (!validacion_leido){

            log_error(kernel_logger, "Comando de CONSOLA no reconocido");
            free(leido);
            leido = readline("> ");
            log_info(logger, leido);
            continue;
        }
        
        atender_instruccion_validada(leido);
		free(leido);
        leido readline("> ");
	}

	free(leido);
}



bool validacion_de_instruccion_de_consola(char* leido){
    bool resultado_validacion = false;
    char** comando_consola = string_split(leido, "");

    if (strcmp(comando_consola[0], "EJECUTAR_SCRIPT") == 0){
        resultado_validacion = true;
    }else if (strcmp(comando_consola[0], "INICIAR_PROCESO") == 0){
        resultado_validacion = true;
    }else if (strcmp(comando_consola[0], "FINALIZAR_PROCESO") == 0){
        resultado_validacion = true;
    }else if (strcmp(comando_consola[0], "DETENER_PLANIFICACION") == 0){
        resultado_validacion = true;
    }else if (strcmp(comando_consola[0], "INICIAR_PLANIFICACION") == 0){
        resultado_validacion = true;
    }else if (strcmp(comando_consola[0], "MULTIPROGRAMACION") == 0){
        resultado_validacion = true;
    }else if (strcmp(comando_consola[0], "PROCESO_ESTADO") == 0){
        resultado_validacion = true;
    }else{
        log_error(kernel_logger, "Comando no reconocido");
        resultado_validacion = false;
    }
    
    string_array_destroy(comando_consola);

    return resultado_validacion;
}



void atender_instruccion_validada(char* leido){
    char** comando_consola = string_split(leido, "");
    t_buffer* un_buffer = crear_buffer();

    if (strcmp(comando_consola[0], "EJECUTAR_SCRIPT") == 0){
        
    }else if (strcmp(comando_consola[0], "INICIAR_PROCESO") == 0){
        cargar_string_al_buffer(un_buffer, comando_consola[1]);
        cargar_string_al_buffer(un_buffer, comando_consola[2]);
        cargar_string_al_buffer(un_buffer, comando_consola[3]);

        f_iniciar_proceso(un_buffer);
    }else if (strcmp(comando_consola[0], "FINALIZAR_PROCESO") == 0){
        
    }else if (strcmp(comando_consola[0], "DETENER_PLANIFICACION") == 0){
        
    }else if (strcmp(comando_consola[0], "INICIAR_PLANIFICACION") == 0){
        
    }else if (strcmp(comando_consola[0], "MULTIPROGRAMACION") == 0){
        
    }else if (strcmp(comando_consola[0], "PROCESO_ESTADO") == 0){
        
    }else{
        log_error(kernel_logger, "Comando no reconocido que logro pasar el filtro!!!");
        exit(EXIT_FAILURE);
    }
    
    string_array_destroy(comando_consola);
    
}


void f_iniciar_proceso(t_buffer* un_buffer){
    char* path = extraer_string_del_buffer(un_buffer);
    char* size = extraer_string_del_buffer(un_buffer);
    char* prioridad = extraer_string_del_buffer(un_buffer);
    log_trace(kernel_logger, "");
    eliminar_buffer(un_buffer);

    int pid = asignar_pid();
    int size_num = atoi(size);

    t_buffer* a_enviar = crear_buffer();
    cargar_int_al_buffer(a_enviar, pid);
    cargar_string_al_buffer(a_enviar, path);
    cargar_int_al_buffer(un_buffer, size_num);

    t_paquete* un_paquete = crear_paquete(CREAR_PROCESO_KERNEL, a_enviar);
    enviar_paquete(un_paquete, fd_memoria);
    eliminar_paquete(un_paquete);

}



int asignar_pid(){
    
    int valor_pid;
    pthread_mutex_lock(&mutex_pid);
    valor_pid = identificador_pid;
    identificador_pid++;
    pthread_mutex_unlock(&mutex_pid);

    return valor_pid;
}