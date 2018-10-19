//
// Created by Anshu on 10/14/18.
// Co-author Arpit Jain
//

#include <stdio.h>
#include <stdlib.h>
#include "writer.h"
#include "queue.h"

void* printOutput(void *arg){

    Queue *munch2ToWriter = (Queue *) arg;
    char *string = DequeueString(munch2ToWriter);

    int i = 0;
    while(string != NULL) {
        i++;
        printf("%s\n", string);
        free(string);
        string = DequeueString(munch2ToWriter);
    }
    fprintf(stderr, "\n\nTOTAL LINES PROCESSED: %d\n\n", i);

    pthread_exit(0);
}
