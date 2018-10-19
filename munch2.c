//
// Created by Anshu on 10/14/18.
//

#include <string.h>
#include <stdlib.h>
#include "munch2.h"


void *convertToLowerCase(void *arg){

    // structure to hold both the queues
    struct_args *args = (struct_args *) arg;

    // Queue between Munch1 and Munch2
    Queue *munch1ToMunch2 = args->q1;

    // Queue between Munch2 and writer
    Queue *munch2ToWriter = args->q2;

    char *data = DequeueString(munch1ToMunch2);

    // If you find a NULL, then terminate the thread
    while (data != NULL){
        int i = 0;
        char *str = strdup(data);
        while (str[i])
        {
            if (str[i] >= 97 && str[i] <= 122)
                str[i] -= 32;
            i++;
        }
        EnqueueString(munch2ToWriter, str);
        data = DequeueString(munch1ToMunch2);
    }

    free(data);

    pthread_exit(0);

}