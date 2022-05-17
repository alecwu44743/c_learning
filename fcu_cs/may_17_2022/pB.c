// 12602 - Nice Licence Plates
// https://vjudge.net/problem/UVA-12602

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


int main(){
    int n;
    char str[10];

    while(scanf("%d", &n) != EOF){
        for(int ccase=0; ccase<n; ccase++){
            scanf("%s", str);

            int alpha = 0;
            int base = 26 * 26;
            int num = 0;

            for(int i=0; i<3; i++){
                alpha += (str[i]-'A') * base;
                base /= 26;
            }

            for(int i=4; i<strlen(str); i++){
                num *= 10;
                num += str[i]-'0';
            }

            printf("%s\n", (abs(alpha - num) <= 100)? "nice" : "not nice");
        }
    }
}