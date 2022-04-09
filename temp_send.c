#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int main(){
    int num;

    while(scanf("%d", &num) && num != 0){
        char appnd;
        char str_bin[1000] = "";
        int cnt = 0;
        int len = 0;

        while(num){
            cnt += (num & 1);
            appnd = '0' + (num & 1);
            strncat(str_bin, &appnd, 1);
            num >>= 1;
        }

        printf("The parity of ");
        for(int i=strlen(str_bin)-1; i>=0; i--){
            printf("%c", str_bin[i]);
        }
        printf(" is %d (mod 2).\n", cnt);
    }
}