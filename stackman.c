#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

const int MAXSIZE = 65536;

// TODO: create a struct for the stack
typedef struct stack {
    int size;
    int* elems;
} stack;


// function prototypes
stack* createstack();
bool isempty(stack* stack);
void deletestack(stack* this);


int main(int argc, char** argv) {

    // init stack
    stack* s = createstack();

    // file IO
    FILE *fp;
    fp = fopen(argv[1], "r");
    int c;

    // loop through file contents
    while ((c = fgetc(fp)) != EOF) {

        // parse arg
        switch (c)
        {
        case '0':
            // push a zero on the top of the stack
            s->elems[0] = 0;
            break;
        
        // if there is an invalid CL arg
        default:
            printf("invalid instruction\n");
            exit(3);
        }
    }
}


// initalize stack function
stack* createstack() {
    stack* this = malloc(sizeof(stack));
    assert(this);
    int* elem_buffer = malloc(sizeof(int));
    assert(elem_buffer);
    this->elems = elem_buffer;
    this->size = 0;
    return this;
} 


bool isempty(stack* stack) {
    return stack->size == 0;
}


void deletestack(stack* this) {
    free(this->elems);
    free(this);
}