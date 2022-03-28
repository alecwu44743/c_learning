#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void _3nplus1(){
    int start, end;

    while(scanf("%d %d", &start, &end)){
        int _max = 0;
        for(int i=start; i<=end; i++){
            int n = i;
            int cnt = 1;
            while(n != 1){
                if(n%2){
                    n = 3*n+1;
                }
                else{
                    n /= 2;
                }
                cnt++;
            }

            if(_max < cnt) _max = cnt;
        }

        printf("%d %d %d\n", start, end, _max);
    }
}

int main(){
    _3nplus1();
}