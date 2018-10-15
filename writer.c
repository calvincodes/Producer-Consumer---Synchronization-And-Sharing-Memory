//
// Created by Anshu on 10/14/18.
//

#include <stdio.h>
#include "writer.h"
#include "queue.h"

void *printOutput(void *arg){
    Queue *queue = (Queue *) arg;
    printf("%s\n",DequeueString(queue));
}