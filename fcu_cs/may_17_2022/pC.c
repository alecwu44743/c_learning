// 10235 - Simply Emirp
// https://onlinejudge.org/external/102/10235.pdf

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int p[1000005] = {0};

int main(){
    p[1] = 1;
    for (int i=2; i < 1000005; i++){
        if (p[i] == 0){
            for (int j=i+i; j < 1000005; j+=i){
                p[j] = 1;
            }
        }
    }

    int n, nn, rn;
    while(scanf("%d", &n) != EOF){
        nn = n;
        rn = 0;

        while(nn){
            rn *= 10;
            rn += nn % 10;
            nn /= 10;
        }

        if(p[n]){
            printf("%d is not prime.\n", n);
        }
        else if(n != rn && p[rn] == 0){
            printf("%d is emirp.\n", n);
        }
        else{
            printf("%d is prime.\n", n);
        }
    }
}