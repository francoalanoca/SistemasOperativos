#include "plani_largo_plazo.h"

/*

void *planificar_largo_plazo();

void iniciar_planificador_largo_plazo()
{
    pthread_create(&hilo_planificador_largo_plazo, NULL, planificar_largo_plazo, NULL);
}

void *planificar_largo_plazo()
{
    // Crear mecanismo para que el hilo muera antes de que el kernel termine
    while (true)
    {
        // Obtenemos procesos para pasar de NEW a READY por FIFO.
        log_trace(logger, "ESPERO proceso en NEW");
        sem_wait(&procesos_new_sem);
        log_trace(logger, "EVENTO proceso en NEW");

        esperar_planificacion();

        // Chequeo de nivel maximo de multiprogramacion
        log_trace(logger, "ESPERO multiprogramacion");
        sem_wait(&nivel_multiprogramacion_sem);
        log_trace(logger, "EVENTO multiprogramacion");

        t_pcb *pcb = (t_pcb *)cola_mutex_pop(procesos_new);
        
        // chequeamos si el pcb no es null, ya que la cola puede estar vacia si justo se finalizaron todos los procesos
        if (pcb == NULL) {
            continue;
        }

        pcb->estado = READY;

        log_info(logger, "PID: %i - Estado Anterior: NEW - Estado Actual: READY", pcb->pid);

        pasar_proceso_a_ready(pcb);
    }
}

*/