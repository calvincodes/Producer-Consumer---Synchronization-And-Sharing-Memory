#include <stdio.h>
#include <unistd.h>
#include "queue.h"
#include "reader.h"
#include "munch1.h"
#include "munch2.h"
#include "writer.h"

int main() {
    pthread_t reader;
    pthread_t munch1;
    pthread_t munch2;
    pthread_t writer;
    printf("Hello, World!\n");
    Queue *queue1 = CreateStringQueue(10);
    Queue *queue2 = CreateStringQueue(10);
    Queue *queue3 = CreateStringQueue(10);
//    if(pthread_create(&reader, NULL, readInput, queue1) != 0){
//        printf("Thread Creation Failed for reader");
//        return 0;
//    }
//    if(pthread_create(&munch1, NULL, replaceBlanks, queue2)!= 0){
//        printf("Thread Creation Failed for Munch1");
//        return 0;
//    }
//    if(pthread_create(&munch2, NULL, convertToLowerCase, queue3)!= 0){
//        printf("Thread Creation Failed for Munch2");
//        return 0;
//    }
    EnqueueString(queue3, "abc");
    EnqueueString(queue3, "defg");
    EnqueueString(queue3, "hijk");
    EnqueueString(queue3, NULL);
    if(pthread_create(&writer, NULL, printOutput, (void *)queue3)){
        printf("Thread Creation Failed for Writer");
        return 0;
    }
//    pthread_join(reader, (void **) &queue);
//    pthread_join(munch1, (void **) &queue);
//    pthread_join(munch2, (void **) &queue);

    pthread_join(writer, NULL);

//    EnqueueString(queue, "defg");
//    EnqueueString(queue, "hijk");


    PrintQueueStats(queue3);
    return 0;
}