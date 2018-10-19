//
// Created by Anshu on 10/14/18.
//

#include "reader.h"
#include <stdio.h>
#include <stdlib.h>

void *readInput(void *arg){

    printf("\n$$$$$$$$$$$$$$$\nREAD THREAD: %ld\n$$$$$$$$$$$$\n",pthread_self());

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
                while (c != '\n') {
                    c = getchar();
                }
                index = 0;
                free(inputBuffer);
                inputBuffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
                continue;
            }

            // Add current character to input buffer
            if (c != '\n') {
                inputBuffer[index++] = (char) c;
            }

            // Check if current character is the end of line for current line
            if (c == '\n') {

                // Add end of line as a terminating character to the buffer
                inputBuffer[index] = '\0';

                printf("Reader added %s\n\n", inputBuffer);

                // Enqueue the input buffer till now in the queue.
                EnqueueString(queue, inputBuffer);
                //printf("%d\n", index);

                // Reset index, free up existing memory and allocate fresh memory for input buffer.
                index = 0;
                inputBuffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
            }
        }
    } while(c != EOF);
    printf("Reached EOF while reading");
    EnqueueString(queue, NULL);

    pthread_exit(0);
}

int main_t() {
    Queue *queue = CreateStringQueue(1500);
    readInput(queue);
    // TODO: Remove. These are for module testing purpose only.
    char *string = DequeueString(queue);
    printf("%s\n", string);
}

