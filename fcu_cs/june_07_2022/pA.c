// UVa 12019 Doom's Day Algorithm
// https://vjudge.net/problem/UVA-12019

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
    char day[7][10] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int m_days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int ccase;
    int m, d;

    while(scanf("%d", &ccase) != EOF){
        while(ccase--){
            scanf("%d %d", &m, &d);

            int sumDays = 0;
            for(int i=0; i<m; i++){
                sumDays += m_days[i];
            }

            printf("%s\n", day[(sumDays+d+5)%7]);
        }
    }
}