//
// Created by Anshu on 10/14/18.
//

#include <stdio.h>
#include "writer.h"
#include "queue.h"

void* printOutput(void *arg){
//    printf("Pthread value %ld",pthread_self());
    Queue *queue = (Queue *) arg;
    printf("%s\n",DequeueString(queue));
    return NULL;
}