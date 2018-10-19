//
// Created by Anshu on 10/19/18.
//

#include "struct_args.h"

struct_args* getCombinedQueue(Queue *q1, Queue *q2){
    struct_args *structure = (struct_args*) malloc(sizeof(struct_args));
    if(!structure){
        fprintf(stderr, "Failed to allocate memory");
        exit(1);
    }
    structure->q1 = q1;
    structure->q2 = q2;
    return structure;
}

