#include <stdio.h>
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
    Queue *queue = CreateStringQueue(10);
//    pthread_create(&reader, NULL, readInput, &queue);
//    pthread_create(&munch1, NULL, replaceBlanks, &queue);
//    pthread_create(&munch2, NULL, convertToLowerCase, &queue);
    EnqueueString(queue, "abc");
    pthread_create(&writer, NULL, printOutput, queue);
//    pthread_join(reader, (void **) &queue);
//    pthread_join(munch1, (void **) &queue);
//    pthread_join(munch2, (void **) &queue);
    pthread_join(writer, (void **) queue);

    EnqueueString(queue, "defg");
    EnqueueString(queue, "hijk");
    printf("%s\n",DequeueString(queue));
    printf("%s",DequeueString(queue));
    printf("%s",DequeueString(queue));
    return 0;
}