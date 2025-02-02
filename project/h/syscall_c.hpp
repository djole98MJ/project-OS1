#ifndef _syscall_c
#define _syscall_c

#include "tcb.hpp"
#include "../lib/hw.h"
#include "sem.hpp"

//---------------------------------------------------------

void* mem_alloc(size_t size);

int mem_free(void* ptr);

//---------------------------------------------------------

typedef TCB _thread;
typedef _thread* thread_t;

int thread_create(
        thread_t* handle,
        void (*start_routine)(void*),
        void* arg
        );

int thread_exit();

void thread_dispatch();

void thread_join(
        thread_t handle
        );
//-----------------------------------------------------------

typedef Sem _sem;
typedef _sem* sem_t;

int sem_open(
        sem_t* handle,
        unsigned init
        );

int sem_close(sem_t handle);

int sem_wait(sem_t handle);

int sem_signal(sem_t handle);

//-----------------------------------------------------------

typedef unsigned long time_t;

//int time_sleep(time_t);

//------------------------------------------------------------

const int EOF = -1;

char getc();

void putc(char);

//------------------------------------------------------------

//dodaci

int thread_create_bez_schedulera(
        thread_t* handle,
        void (*start_routine)(void*),
        void* arg
);

#endif