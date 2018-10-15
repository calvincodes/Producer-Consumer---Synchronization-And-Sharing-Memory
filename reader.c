//
// Created by Anshu on 10/14/18.
//

#include "reader.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void *readInputTemp(void *arg){

    Queue *queue = (Queue *) arg;
    char *inputBuffer;
    size_t bufferSize = 32;

    inputBuffer = (char *)malloc(bufferSize * sizeof(char));
    if( inputBuffer == NULL)
    {
        perror("Unable to allocate memory for reader input buffer");
        exit(-1);
    }

    // Read the input file till you detect an EOF character
    long long int M;
    do {
        getline(&inputBuffer,&bufferSize,stdin);
        EnqueueString(queue, inputBuffer);
        char *string = DequeueString(queue);
        printf("%s\n", string);
    } while(scanf("%lld", &M)!= EOF);

    EnqueueString(queue, NULL);

    return(0);
}

int main() {
    Queue *queue = CreateStringQueue(10);
    readInputTemp(queue);
}