#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct test{
    int *n;
};
typedef struct test test;


int main(){
    test num;

    num.n = malloc(sizeof(int)*10);

    for(int i=0; i<10; i++){
        num.n[i] = i;
    }

    for(int i=0; i<10; i++){
        printf("%d\n", num.n[i]);
    }
}