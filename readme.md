# pthreads-c 

**pthreads-c** is a documentation-focused repository that captures the journey of learning and experimenting with multithreading in C using the **POSIX Threads (pthreads) library**. Instead of just providing educational content, this repository **documents discoveries, challenges, and practical implementations** encountered along the way.

The project serves as a **living record** of multithreading exploration, covering various use cases, synchronization techniques, and debugging strategies.

## **What is a thread?**

A **thread** is the basic unit of execution within a process. It allows a program to perform multiple tasks concurrently, sharing the same memory space but executing independently. In C, threads are commonly managed using the **POSIX Threads (pthreads)** library, which provides functions for creating, synchronizing, and controlling threads, facilitating the development of efficient, concurrent applications.

## **Contents**
### Thread Creation & Management
- Initializing threads with `pthread_create()`.
- Passing data to threads through arguments.
- Handling errors during thread initialization.

### Thread Execution & Behavior
- Defining multiple thread functions.
- Printing thread identifiers (`pthread_self()`).
- Using loops (`for` and `while`) to control execution order.

### Thread Synchronization & Exit Mechanisms
- Using `pthread_exit()` to terminate threads safely.
- Ensuring execution completion with `pthread_join()`.
- Managing thread data with pointers (`void *` return values).

### Debugging & Error Handling
- Checking return values from `pthread_create()`.
- Identifying failed thread creation cases.
- Debugging thread execution using print statements.

## **How to Use pthreads-c**
  - **Browse** through documented learning experiences and implementations.  
  - **Use** the code snippets to experiment with pthreads in your own projects.  
  - **Compile** with pthreads support:
  
```bash
   gcc example.c -o example -pthread
```

## Credits

This repository is maintained and designed by Badjavii, a junior developer.