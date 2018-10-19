//
// Created by Anshu on 10/14/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "munch1.h"

void *replaceBlanks(void *arg){

//    printf("\n$$$$$$$$$$$$$$$\nMUNCH1 THREAD: %ld\n$$$$$$$$$$$$\n",pthread_self());

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
//        char *str = strdup(data);
        char *str = data;
        //free(data);
        while (str[i])
        {
            if (str[i] == ' ')
                str[i] = '*';
            i++;
        }
//        printf("munch1 added %s\n\n", str);
        EnqueueString(munch1ToMunch2, str);
        //free(str);
        data = DequeueString(readerToMunch1);
    }
    EnqueueString(munch1ToMunch2, NULL);

    //free(data);

    pthread_exit(0);
}

// TODO: Remove. This is for module testing purpose only.
//int main() {
//    Queue *queue = CreateStringQueue(10);
//    Queue *queue1 = CreateStringQueue(10);
//    struct_args * structMunch1 = (struct_args *) malloc(sizeof(struct_args));
//    structMunch1->q1 = queue;
//    structMunch1->q2 = queue1;
//    EnqueueString(queue, "arpit jain");
//    EnqueueString(queue, "anshu verma vishnu");
//    EnqueueString(queue, "dotSru susma");
//    EnqueueString(queue, NULL);
//    replaceBlanks(structMunch1);
//}
