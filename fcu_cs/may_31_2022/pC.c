// UVA1583 - Digit Generator
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=4458

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
    int data[100000] = {0};

    for(int i=1; i<=100000; i++){
        int n = i;
        int digitSum = 0;

        while(n > 0){
            digitSum += n%10;
            n /= 10;
        }

        if(data[i + digitSum] == 0){
            data[i + digitSum] = i;
        }
    }

    int ccase;
    int num;
    while(scanf("%d", &ccase) != EOF){
        for(int i=0; i<ccase; i++){
            scanf("%d", &num);
            printf("%d\n", data[num]);
        }
    }
}