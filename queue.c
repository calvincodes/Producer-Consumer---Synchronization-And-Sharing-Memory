//
// Created by Anshu on 10/14/18.
// Co-author Arpit Jain
//

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include "queue.h"


Queue *CreateStringQueue(int size) {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if(!queue){
        fprintf(stderr, "Could not allocate memory for queue data");
        exit(1);
    }
    queue->size = size;
    queue->front = 0;
    queue->currSize = 0;
    queue->rear = size - 1;
    queue->data = (char **) malloc(queue->size * sizeof(char*));
    if (!queue->data) {
        fprintf(stderr, "Could not allocate memory for queue data");
        exit(1);
    }
    queue->dequeueBlockCount = 0;
    queue->enqueueBlockCount = 0;
    queue->dequeueCount = 0;
    queue->enqueueCount = 0;
    pthread_cond_init(&queue->full, NULL);
    pthread_cond_init(&queue->empty, NULL);
    pthread_mutex_init(&queue->lock, NULL);
    return queue;
}


int isFull(Queue *queue) {
    return (queue->size == queue->currSize);
}

int isEmpty(Queue *queue) {
    return (queue->currSize == 0);
}

void EnqueueString(Queue *q, char *string) {
    pthread_mutex_lock(&q->lock);
    if (isFull(q)) {
        if (string != NULL) {
            ++q->enqueueBlockCount;
        }
        pthread_cond_wait(&q->full, &q->lock);
        // Block the mutex
    }

    q->rear = (q->rear + 1) % q->size;
    q->data[q->rear] = string;
    q->currSize = q->currSize + 1;
    if (string != NULL) {
        ++q->enqueueCount;
    }

    pthread_cond_signal(&q->empty);
    pthread_mutex_unlock(&q->lock);
}

char *DequeueString(Queue *q) {
    pthread_mutex_lock(&q->lock);
    if (isEmpty(q)) {
        ++q->dequeueBlockCount;
        pthread_cond_wait(&q->empty, &q->lock);
        // Block the mutex
    }

    char *data = q->data[q->front];
    q->front = (q->front + 1) % q->size;
    q->currSize = q->currSize - 1;
    if (data != NULL) {
        ++q->dequeueCount;
    }

    pthread_cond_signal(&q->full);
    pthread_mutex_unlock(&q->lock);
    return data;

}

void PrintQueueStats(Queue *q) {
    fprintf(stderr, "\nenqueueCount : %d\n", q->enqueueCount);
    fprintf(stderr, "dequeueCount : %d\n", q->dequeueCount);
    fprintf(stderr, "enqueueBlockCount: %d\n", q->enqueueBlockCount);
    fprintf(stderr, "dequeueBlockCount: %d\n", q->dequeueBlockCount);
}



