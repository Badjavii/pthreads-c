#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h> // Including standart library for threads management

/*
 * @brief this function print on screen the message using a thread
*/

void *say_by_threads(){

    printf("Hello world");
}

int main(){

    pthread_t new_thread;   // variable in thread type
    int result;             // integer that contains the result of the creation of the thread

    // At this point, the thread has not been created yet.
    // For create the thread we must use pthread_create function.
    // The function will return an intenger number. It will return 0 if the thread has been created correctly.


    result = pthread_create(&new_thread, NULL, say_by_threads(), NULL);

    if (result != 0) return -1;

    return 0;
}
