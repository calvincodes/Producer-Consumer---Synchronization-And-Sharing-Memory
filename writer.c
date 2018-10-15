//
// Created by Anshu on 10/14/18.
//

#include <stdio.h>
#include "writer.h"
#include "queue.h"

void* printOutput(void *arg){
//    printf("Pthread value %ld",pthread_self());

    Queue *queue = (Queue *) arg;
    char *string = DequeueString(queue);
    while(string != NULL){
        printf("%s\n", string);
        string = DequeueString(queue);
    }
    return NULL;
}