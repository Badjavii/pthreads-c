/*
 * PROPOSITO DEL CÓDIGO:
 * Este programa demuestra la creación y manejo básico de hilos POSIX (pthreads).
 * Crea múltiples hilos que comparten una variable global (data) para mostrar:
 * 1. Cómo los hilos pueden ejecutarse concurrentemente
 * 2. Problemas de concurrencia (condiciones de carrera)
 * 3. Diferentes cargas de trabajo entre hilos
 *
 * ADVERTENCIA: Este código contiene condiciones de carrera deliberadas para fines didácticos.
 */

#include <stdlib.h>  // Para EXIT_SUCCESS/FAILURE
#include <stdio.h>   // Para printf()
#include <pthread.h> // Para funciones de hilos POSIX

/*
 * FUNCIONES PRINCIPALES DE pthread.h:
 *
 * 1. pthread_create() - Crea un nuevo hilo
 *    Parámetros:
 *    - pthread_t*: Variable para almacenar el ID del hilo
 *    - const pthread_attr_t*: Atributos del hilo (NULL = predeterminados)
 *    - void* (*start_routine)(void*): Función que ejecutará el hilo
 *    - void*: Argumento para pasar a la función
 *
 * 2. pthread_exit() - Termina el hilo actual
 *    - void*: Valor de retorno que puede ser obtenido por pthread_join()
 *
 * 3. pthread_join() - Espera a que un hilo termine
 *    - pthread_t: ID del hilo a esperar
 *    - void**: Donde almacenar el valor de retorno del hilo
 *
 * 4. pthread_self() - Obtiene el ID del hilo actual
 *
 * 5. pthread_mutex_* - Funciones para exclusión mutua (no usadas en este ejemplo)
 */

void *thread_UNE(void *data)
{
    /* Hilo con carga pesada (1,000,000 iteraciones) */
    (*(int *)data)++; // Condición de carrera deliberada
    printf("\n\t\t Hilo LARGO entrando: [%lu]", pthread_self());
    for (int z = 0; z < 1000000; z++)
        ; // Simula trabajo
    printf("\n\t\t Hilo LARGO saliendo: [%lu]", pthread_self());
    pthread_exit(data);
}

void *thread_DEUX(void *data)
{
    /* Hilo con carga ligera (10 iteraciones) */
    (*(int *)data)++; // Condición de carrera deliberada
    printf("\n\t\t Hilo CORTO entrando: [%lu]", pthread_self());
    for (int z = 0; z < 10; z++)
        ; // Simula trabajo
    printf("\n\t\t Hilo CORTO saliendo: [%lu]", pthread_self());
    pthread_exit(data);
}

int main()
{
    /* Configuración inicial */
    pthread_t new_thread;     // Almacena ID del hilo
    int data = 0;             // Variable compartida (contador)
    int thread_rc;            // Para verificar errores
    const int max_ciclos = 6; // Número de iteraciones

    printf("\n\t\t MAIN iniciado: [%lu]", pthread_self());

    /* Creación de hilos en bucle */
    for (int i = 0; i < max_ciclos; i++)
    {
        printf("\n Ciclo %d", i);

        // Crea 1 hilo largo y 2 cortos por ciclo
        pthread_create(&new_thread, NULL, thread_UNE, &data);
        pthread_create(&new_thread, NULL, thread_DEUX, &data);
        pthread_create(&new_thread, NULL, thread_DEUX, &data);
    }

    /* Espera solo al último hilo creado (problema deliberado) */
    int *resultado;
    pthread_join(new_thread, (void **)&resultado);
    printf("\n MAIN terminado. Contador final: %d", *resultado);

    return EXIT_SUCCESS;
}