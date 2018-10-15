//
// Created by Anshu on 10/14/18.
//

#include <stdlib.h>
#include <pthread.h>
#include "queue.h"

Queue *CreateStringQueue(int size){
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->size = size;
    queue->front = 0;
    queue->currSize = 0;
    queue->rear = size - 1;
    queue->data = (char**) malloc(queue->size * sizeof(char*));
    queue->dequeueBlockCount = 0;
    queue->enqueueBlockCount = 0;
    queue->dequeueCount = 0;
    queue->enqueueCount = 0;
    return queue;
}


int isFull(Queue* queue)
{
    return (queue->size == queue->currSize);
}

int isEmpty(Queue* queue)
{
    return (queue->currSize == 0);
}

void EnqueueString(Queue *q, char *string){
    if (isFull(q)){
        pthread_cond_wait(&q->full, &q->lock);
        q->enqueueBlockCount++;
        // Block the mutex
    }
    pthread_mutex_lock(&q->lock);
    q->rear = (q->rear + 1)%q->size;
    q->data[q->rear] = string;
    q->currSize = q->currSize + 1;
    q->enqueueCount++;
    pthread_mutex_unlock(&q->lock);
    pthread_cond_signal(&q->empty);
}

char *DequeueString(Queue *q){
    if (isEmpty(q)){
        pthread_cond_wait(&q->empty, &q->lock);
        // Block the mutex
        q->dequeueBlockCount++;
    }
    pthread_mutex_lock(&q->lock);
    char* data = q->data[q->front];
    q->front = (q->front + 1)%q->size;
    q->size = q->size - 1;
    q->dequeueCount++;
    pthread_mutex_unlock(&q->lock);
    pthread_cond_signal(&q->full);
    return data;
}

void PrintQueueStats(Queue *q){

}



