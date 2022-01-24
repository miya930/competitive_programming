#include <stdio.h>
#include <stdint.h>

typedef struct {
    int32_t foo;
    int32_t foofoo;
} tobj_t;

int main(void) {
    tobj_t x = {10, 21};    // Object Dictionary
    tobj_t* p = &x;

    printf("x = %d, xptr = %p\n", x, &x);

}