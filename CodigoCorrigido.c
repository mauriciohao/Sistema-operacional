//Nome:Hao Yue Zheng - 10408948
//Nome:Samuel Zheng - 10395781
//Nome:Vitor Pasquarelli Cinalli - 10401806
// PROJ1 -Concorrência

#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <pthread.h> // Inclusão da biblioteca pthread

// 64kB stack
#define FIBER_STACK 1024*64
#define NUM_TRANSFERS 20

struct c {
    int saldo;
};

typedef struct c conta;

conta from, to;

// Variável para controlar o acesso concorrente
pthread_mutex_t transfer_mutex; // Declaração do mutex

// The child thread will execute this function
void* transferencia(void *arg) {
    int i;
    for(i = 0; i < NUM_TRANSFERS; i++) {
        // Bloqueia o mutex
        pthread_mutex_lock(&transfer_mutex);

        // Tranfere de c1 para c2
        if(from.saldo >= 10) {
            from.saldo -= 10;
            to.saldo += 10;  
        }

        // Quando c1 zerar, inverte as contas
        if(from.saldo == 0) {
            conta tmp = from;
            from = to;
            to = tmp;
        }

        // Exibe saldos
        printf("c1: %d\nc2: %d\n", from.saldo, to.saldo);

        // Libera o mutex
        pthread_mutex_unlock(&transfer_mutex);
    }
    return NULL;
}

int main() {
    void* stack;
    pthread_t thread;
    int i;

    // Inicialização do mutex
    pthread_mutex_init(&transfer_mutex, NULL);

    stack = malloc(FIBER_STACK);
    if (stack == NULL) {
        perror("malloc: could not allocate stack");
        exit(1);
    }

    from.saldo = 100; 
    to.saldo = 0;
    printf("Transferindo 10 para a conta c2\n");

    for (i = 0; i < 2; i++) {
        pthread_create(&thread, NULL, transferencia, NULL);
        pthread_join(thread, NULL);  // Espera a thread terminar
    }

    // Destruição do mutex
    pthread_mutex_destroy(&transfer_mutex);

    // Free the stack
    free(stack);
    printf("Transferências concluídas e memória liberada.\n");

    return 0;
}
