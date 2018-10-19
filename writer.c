//
// Created by Anshu on 10/14/18.
//

#include <stdio.h>
#include "writer.h"
#include "queue.h"

void* printOutput(void *arg){

    printf("\n$$$$$$$$$$$$$$$\nWRITER THREAD: %ld\n$$$$$$$$$$$$\n",pthread_self());

    Queue *munch2ToWriter = (Queue *) arg;
    char *string = DequeueString(munch2ToWriter);
    //printf("Initiating dequeue\n\n");
    //printf("First string dequeued: %s\n", string);
    int i = 0;
    while(string != NULL){
        printf("Dequeue String is %s\n", string);
        //free(string);
        printf("Dequeued %d\n", i++);
        string = DequeueString(munch2ToWriter);
    }
    //printf("last string to writer: %s\n", string);
    pthread_exit(0);
}
