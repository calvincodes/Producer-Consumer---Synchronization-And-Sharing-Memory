//
// Created by Anshu on 10/14/18.
//

#include "reader.h"
#include <stdio.h>
#include <stdlib.h>

void *readInput(void *arg){

    Queue *queue = (Queue *) arg;
    char *inputBuffer;

    inputBuffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
    if( inputBuffer == NULL)
    {
        perror("Unable to allocate memory for reader input buffer");
        exit(1);
    }

    int c;
    int index = 0;
    do {
        c = getchar();
        // Any processing is required only if encountered character is NOT EOF.
        if (c != EOF) {
            // If character read is not terminating this line and buffer is exhausted, throw error.
            if (index >= BUFFER_SIZE) {
                fprintf(stderr, "Line size exceeds buffer size %d", BUFFER_SIZE);
                exit(-1);
            }

            // Add current character to input buffer
            if (c != '\n') {
                inputBuffer[index++] = (char) c;
            }

            // Check if current character is the end of line for current line
            if (c == '\n') {

                // Add end of line as a terminating character to the buffer
                inputBuffer[index] = '\0';

                // Enqueue the input buffer till now in the queue.
                EnqueueString(queue, inputBuffer);

                // TODO: Remove. These are for module testing purpose only.
//                char *string = DequeueString(queue);
//                printf("%s\n", string);

                // Reset index, free up existing memory and allocate fresh memory for input buffer.
                index = 0;
                free(inputBuffer);
                inputBuffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
            }
        }
    } while(c != EOF);

    EnqueueString(queue, NULL);

    pthread_exit(0);
}

