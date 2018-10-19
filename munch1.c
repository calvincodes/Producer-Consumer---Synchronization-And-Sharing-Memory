//
// Created by Anshu on 10/14/18.
//

#include <stdio.h>
#include <string.h>
#include "munch1.h"

void *replaceBlanks(void *arg){

    Queue *queue = (Queue *) arg;
    char *data = DequeueString(queue);

//    while (string != NULL) {
//
//        char *dupString = strdup(string);
//
//        int index = 0;
//        char c = dupString[index];
//
//        while (c != '\0') {
//            if (c == ' ') {
//                dupString[index] = '*';
//            }
//            index++;
//            c = dupString[index];
//        }
//
////        printf("%s\n", dupString);
//        string = DequeueString(queue);
//        printf("NEW STR \n");
//        printf("%s\n", string);
//    }
    while(data != NULL){
        int i=0;
        char *str = strdup(data);
        while (str[i]){
            if(str[i] == ' '){
                str[i] = '*';
            }
            i++;
        }
        printf("%s\n", str);
        data = DequeueString(queue);
    }

}

// TODO: Remove. This is for module testing purpose only.
int main_t() {
    Queue *queue = CreateStringQueue(10);
    EnqueueString(queue, "arpit jain");
    EnqueueString(queue, "anshu verma vishnu");
    EnqueueString(queue, "dotSru susma");
    EnqueueString(queue, NULL);
    replaceBlanks(queue);
}
