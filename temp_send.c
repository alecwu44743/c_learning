#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int main(){
    int x, y;
    
    while(scanf("%d %d", &x, &y)){
        if(x==0 && y==0) break;

        int max_seq = 0;
        for(int i=x; i<=y; i++){
            int n = i;
            int cnt = 1;
            while(n != 1){
                if(n%2) n = 3*n+1;
                else n /= 2;
                cnt++;
            }
            if(max_seq < cnt) max_seq = cnt;
        }

        printf("%d %d %d\n", x, y, max_seq);
    }
}