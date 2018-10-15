//
// Created by Anshu on 10/14/18.
//

#ifndef OS_HW2_QUEUE_H
#define OS_HW2_QUEUE_H

#endif //OS_HW2_QUEUE_H
#include <pthread.h>

typedef struct queue {
    int front;
    int rear;
    int size;
    int currSize;
    int enqueueCount;
    int dequeueCount;
    int enqueueBlockCount;
    int dequeueBlockCount;
    pthread_mutex_t lock;
    pthread_cond_t full;
    pthread_cond_t empty;
    char** data;
} Queue;

Queue *CreateStringQueue(int size);

void EnqueueString(Queue *q, char *string);

char *DequeueString(Queue *q);

void PrintQueueStats(Queue *q);

