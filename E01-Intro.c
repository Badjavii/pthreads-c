#include <pthread.h> // Including standart library for threads management
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @file pthreads.c
 * @brief Demonstrates basic usage of POSIX threads (pthreads) in C.
 *
 * This program creates a new thread that prints "Hello world" to the screen.
 * It showcases the use of the pthread_create function and basic thread management.
 *
 * @author badjavii
 * @date 2025
 */

/**
 * @brief Thread function that prints a message to the screen.
 *
 * This function is intended to be executed by a separate thread.
 * It prints "Hello world" to the standard output.
 *
 * @param arg Unused parameter.
 * @return Always returns NULL.
 */

void *say_by_threads(void *args)
{
    printf("Hello world");
    return NULL;
}

/**
 * @brief Entry point of the program.
 *
 * Creates a new thread that runs the say_by_threads function.
 * Checks for successful thread creation and returns -1 on failure.
 *
 * @return Returns 0 on success, -1 if thread creation fails.
 */

int main()
{

    pthread_t new_thread; // variable in thread type
    int result;           // integer that contains the result of the creation of the thread

    // At this point, the thread has not been created yet.
    // For create the thread we must use pthread_create function.
    // The function will return an intenger number. It will return 0 if the thread has been created correctly.

    result = pthread_create(&new_thread, NULL, say_by_threads(), NULL);

    if (result != 0)
        return EXIT_FAILURE; // If the thread has not been created correctly, we return -1

    return EXIT_SUCCESS; // If the thread has been created correctly, we return 0
}
