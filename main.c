#include <stdio.h>
#include "queue.h"

int main() {
    printf("Hello, World!\n");
    Queue *queue = CreateStringQueue(10);
    EnqueueString(queue, "abc");
    EnqueueString(queue, "defg");
    EnqueueString(queue, "hijk");
    printf("%s\n",DequeueString(queue));
    printf("%s",DequeueString(queue));
    return 0;
}