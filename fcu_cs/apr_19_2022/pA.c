#include <stdlib.h>
#include <stdio.h>

#define DAY 24*60

int main(){
    int h, m;
    int hh, mm;

    while(scanf("%d %d %d %d", &h, &m, &hh, &mm) != EOF){
        if(h == 0 && m == 0 && hh == 0 && mm == 0) break;

        m = h*60 + m;
        mm = hh*60 +mm;

        if(m > mm){
            m -= mm;
            m = DAY - m;
        }
        else{
            mm -= m;
            m = mm;
        }

        printf("%d\n", m);
    }
}