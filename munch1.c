//
// Created by Anshu on 10/14/18.
// Co-author Arpit Jain
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "munch1.h"

void *replaceBlanks(void *arg){

    // structure to hold both the queues
    struct_args *args = (struct_args *) arg;

    // Queue between Munch1 and Munch2
    Queue *readerToMunch1 = args->q1;

    // Queue between Munch2 and writer
    Queue *munch1ToMunch2 = args->q2;

    char *data = DequeueString(readerToMunch1);

    // If you find a NULL, then terminate the thread
    while (data != NULL){
        int i = 0;
        while (data[i])
        {
            if (data[i] == ' ')
                data[i] = '*';
            i++;
        }

        EnqueueString(munch1ToMunch2, data);
        data = DequeueString(readerToMunch1);
    }
    EnqueueString(munch1ToMunch2, NULL);

    pthread_exit(0);
}

