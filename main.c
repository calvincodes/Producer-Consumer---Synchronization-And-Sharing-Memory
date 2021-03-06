//
// Created by Anshu on 10/14/18.
// Co-author Arpit Jain
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <execinfo.h>
#include <signal.h>
#include "reader.h"
#include "munch1.h"
#include "munch2.h"
#include "writer.h"

int main() {

    pthread_t reader;
    pthread_t munch1;
    pthread_t munch2;
    pthread_t writer;

    // Queue initialisation
    Queue *readerToMunch1 = CreateStringQueue(BUFFER_SIZE);
    Queue *munch1ToMunch2 = CreateStringQueue(BUFFER_SIZE);
    Queue *munch2ToWriter = CreateStringQueue(BUFFER_SIZE);

    // thread Creation
    if(pthread_create(&reader, NULL, readInput, readerToMunch1) != 0){
        fprintf(stderr, "Thread Creation Failed for reader");
        return 2;
    }
    if(pthread_create(&munch1, NULL, replaceBlanks, getCombinedQueue(readerToMunch1, munch1ToMunch2))!= 0){
        fprintf(stderr, "Thread Creation Failed for Munch1");
        return 2;
    }
    if(pthread_create(&munch2, NULL, convertToLowerCase, getCombinedQueue(munch1ToMunch2, munch2ToWriter))!= 0){
        fprintf(stderr, "Thread Creation Failed for Munch2");
        return 2;
    }

    if(pthread_create(&writer, NULL, printOutput, (void *)munch2ToWriter)){
        fprintf(stderr, "Thread Creation Failed for Writer");
        return 2;
    }

    // thread Destroy
    if(pthread_join(reader, (void **) NULL) != 0){
        fprintf(stderr, "Thread join Failed for Reader");
        return  2;
    }
    if(pthread_join(munch1, (void **) NULL) != 0){
        fprintf(stderr, "Thread join Failed for Munch1");
        return 2;
    }
    if(pthread_join(munch2, (void **) NULL) != 0){
        fprintf(stderr, "Thread join Failed for Munch2");
        return 2;
    }

    if (pthread_join(writer, (void **) NULL) != 0){
        fprintf(stderr, "Thread join Failed for Writer");
        return 2;
    }

    fprintf(stderr, "\nStatistics of Reader To Munch1 Queue");
    PrintQueueStats(readerToMunch1);
    fprintf(stderr, "\nStatistics of Munch1 To Munch2 Queue");
    PrintQueueStats(munch1ToMunch2);
    fprintf(stderr, "\nStatistics of Munch2 To Writer Queue");
    PrintQueueStats(munch2ToWriter);
    return 0;
}
