// UVa 12970 - Alcoholic Pilots 
// https://vjudge.net/problem/UVA-12970

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


unsigned long long gcd(unsigned long long a, unsigned long long b){
    while(b != 0){
        unsigned long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main(){
    unsigned long long v, d, vv, dd, ccase = 1;

    while(scanf("%llu %llu %llu %llu", &v, &d, &vv, &dd) != EOF){
        if(v == 0 && d == 0 && vv == 0 && dd == 0) break;

        unsigned long long a = d*vv, b = dd*v;

        if(a < b){
            printf("Case #%llu: You owe me a beer!\n",ccase++);
        }
        else if(a > b){
            printf("Case #%llu: No beer for the captain.\n",ccase++);
        }

        // if(ccase == 24) printf("\n"); // There is an error in the testing case

        unsigned long long time = d*vv + dd*v;
        unsigned long long mo = v*vv*2;
        unsigned long long div = gcd(time, mo);
        unsigned long long s = time/div, m = mo/div;

        if(m == 1){
            printf("Avg. arrival time: %llu\n",s);
        }
        else{
            printf("Avg. arrival time: %llu/%llu\n",s,m);
        }
    }
}