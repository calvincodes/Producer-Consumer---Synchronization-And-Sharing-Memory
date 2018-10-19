//
// Created by Anshu on 10/14/18.
// Co-author Arpit Jain
//

#include "reader.h"
#include <stdio.h>
#include <stdlib.h>

void *readInput(void *arg){

    Queue *queue = (Queue *) arg;
    char *inputBuffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

    if( inputBuffer == NULL)
    {
        fprintf(stderr, "Unable to allocate memory for reader input buffer");
        exit(1);
    }

    int c;
    unsigned int index = 0;
    do {

        c = getchar();

        // If character read is not terminating this line and buffer is exhausted:
        // Print it to stderr and discard this line.
        if (index >= BUFFER_SIZE) {
            inputBuffer[index-1] = '\0';
            while (c != '\n' && c != EOF) {
                c = getchar();
            }
            fprintf(stderr, "THIS LINE EXHAUSTED THE BUFFER SIZE %d AND HAS BEEN DISCARDED\n", BUFFER_SIZE);
            index = 0;
            free(inputBuffer);
            inputBuffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
            continue;
        }

        // Add current character to input buffer
        if (c != '\n' && c != EOF) {
            inputBuffer[index++] = (char) c;
        }

        // Check if current character is the end of line for current line
        if (c == '\n' || c == EOF) {

            if (index == 0 && c == EOF) {
                continue;
            }

            // Add end of line as a terminating character to the buffer
            if (c == '\n') {
//                inputBuffer[index] = '\n';
                inputBuffer[index] = '\0';
            }

            // Enqueue the input buffer till now in the queue.
            EnqueueString(queue, inputBuffer);

            // Reset index, free up existing memory and allocate fresh memory for input buffer.
            index = 0;
            inputBuffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
            if( inputBuffer == NULL)
            {
                fprintf(stderr, "Unable to allocate memory for reader input buffer");
                exit(1);
            }
        }

    } while(c != EOF);

    EnqueueString(queue, NULL);

    pthread_exit(0);
}

