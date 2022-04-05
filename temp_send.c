#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int main(){
    char str[100];
    int data[26];

    for(int i=0; i<18; i++){
        data[i] = i / 3 + 2;
    }
    data[18] = 7;
    data[19] = data[20] = data[21] = 8;
    data[22] = data[23] = data[24] = data[25] = 9;

    while(scanf("%s", str) != EOF){
        int alpha = 0;
        int hyphen = 0;

        for(int i=0; i<strlen(str); i++){
            if(isalpha(str[i])){
                printf("%d", data[str[i] - 'A']);
                alpha++;
            }
            else if(str[i] == '-'){
                printf("%c", str[i]);
                hyphen++;
            }
            else{
                printf("%c", str[i]);
            }
        }
        printf("\n");
        // printf(" %d %d\n", alpha, hyphen);
    }
}