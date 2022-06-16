#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct test{
    int *n;
};
typedef struct test test;


int main(){
    // test num;

    // num.n = malloc(sizeof(int)*10);

    // for(int i=0; i<10; i++){
    //     num.n[i] = i;
    // }

    // for(int i=0; i<10; i++){
    //     printf("%d\n", num.n[i]);
    // }

    // char str[20] = "D=C[0:2,1:3]";
    // char dd;
    // int a, aa, b, bb;


    // // scanf("%s", str); // D= C [   0:2,1:3]
    // sscanf(str, "%c=%c[%d:%d,%d:%d]", &dd, &dd, &a, &aa, &b, &bb);

    // printf("%c %d %d %d %d\n", dd, a, aa, b, bb);



    // char *ret;
    // char input[100];


    // while(scanf("%s", input)){
    //     ret = strstr(input, "[");

    //     if(ret){
    //         printf("%s\n", "yes");
    //     }
    //     else{
    //         printf("%s\n", "no");
    //     }
    // }

    int r = 5000, c = 5000, i, j, count;
 
        double **arr = (double**)malloc(r * sizeof(double*) + r*c*sizeof(double));


    printf("ok\n");

}