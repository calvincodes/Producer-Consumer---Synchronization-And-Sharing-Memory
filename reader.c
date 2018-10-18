//
// Created by Anshu on 10/14/18.
//

#include "reader.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "constants.h"

void *readInputTemp(void *arg){

    Queue *queue = (Queue *) arg;
    char *inputBuffer;

    inputBuffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
    if( inputBuffer == NULL)
    {
        perror("Unable to allocate memory for reader input buffer");
        exit(-1);
    }

    int c;
    int index = 0;
    do {
        c = getchar();
        // Any processing is required only if encountered character is NOT EOF.
        if (c != EOF) {
            // If character read is not terminating this line and buffer is exhausted, throw error.
            if (index >= BUFFER_SIZE && c != '\n') {
                fprintf(stderr, "Line size exceeds buffer size %d", BUFFER_SIZE);
                exit(-1);
            }

            // Add to buffer if there is space available.
            // Corner case here is, if your input string is of same length as buffer size and the newLine is
            // the character at BUFFER_SIZE index. In this case, we will not throw error. Rather we have the
            // entire line in our buffer and we will simply read the entire buffer everywhere, till be reach
            // the end of buffer or we encounter a '\n' character.
            if (index < BUFFER_SIZE) {
                // Add current character to input buffer
                inputBuffer[index++] = (char) c;
            }

            // Check if current character is the end of line for current line
            if (c == '\n') {

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

    return(0);
}

// TODO: Remove. This is for module testing purpose only.
//int main() {
//    Queue *queue = CreateStringQueue(10);
//    readInputTemp(queue);
//}