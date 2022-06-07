// UVa 12869 - Zeroes
// https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/12869.pdf

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


int main(){
    long long int l, h;

    while(scanf("%lld %lld", &l, &h) != EOF){
        if(l == 0 && h == 0) break;

        printf("%lld\n", (h/5) - (l/5) + 1);
    }
}