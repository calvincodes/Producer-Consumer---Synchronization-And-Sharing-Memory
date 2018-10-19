//
// Created by Anshu on 10/14/18.
//

#include <stdio.h>
#include <stdlib.h>
#include "writer.h"
#include "queue.h"

void* printOutput(void *arg){

    Queue *munch2ToWriter = (Queue *) arg;
    char *string = DequeueString(munch2ToWriter);

    while(string != NULL) {
        printf("%s", string);
        string = DequeueString(munch2ToWriter);
    }

    pthread_exit(0);
}
