#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *thread_UNE(void *data)
{

    (*(int *)data)++;
    printf("\n\t\t Enter thread: [%i]", pthread_self());

    for (int z = 0; z < 1000000; z++)
        ;

    printf("\n\t\t Exit thread [%i]", pthread_self());

    pthread_exit(data);
}

void *thread_DEUX(void *data)
{

    (*(int *)data)++;
    printf("\n\t\t Enter thread: [%i]", pthread_self());

    for (int z = 0; z < 10; z++)
        ;

    printf("\n\t\t Exit thread [%i]", pthread_self());

    pthread_exit(data);
}

int main()
{

    pthread_t new_thread; // variable in thread type
    int data = 0;         // integer that cointains the number of threads created
    int thread_rc = 0;    // integer that cointains the return code of the thread
    int i = 0;            // counter variable
    int max_cicles = 6;   // maximum number of cycles

    printf("\n\t\t Enter main thread: [%i]", pthread_self());

    while (i < max_cicles)
    {

        printf("\n Cicle Number: %i", i);
        printf("\n\t\t Enter main thread: [%i]", pthread_self());

        thread_rc = pthread_create(&new_thread, NULL, thread_UNE, &data);

        if (thread_rc != 0)
        {

            printf("\n\t\t Error creating thread [%i]", thread_rc);
            return EXIT_FAILURE;
        }

        printf("\n\t First condition");

        thread_rc = pthread_create(&new_thread, NULL, thread_DEUX, &data);
        if (thread_rc != 0)
        {

            printf("\n\t\t Error creating thread [%i]", thread_rc);
            return EXIT_FAILURE;
        }

        printf("\n\t Second condition");

        thread_rc = pthread_create(&new_thread, NULL, thread_DEUX, &data);
        if (thread_rc != 0)
        {

            printf("\n\t\t Error creating thread [%i]", thread_rc);
            return EXIT_FAILURE;
        }

        printf("\n\t Third condition");
        i++;
    }

    int *ptr_output_data;

    pthread_join(new_thread, (void **)&ptr_output_data); // Wait for the thread to finish and get the return value

    printf("\nEnd of main thread: [%i]", pthread_self(), *ptr_output_data); // Print the thread ID and the return value

    return EXIT_SUCCESS;
}