// UVA 272 - TEX Quotes
// https://onlinejudge.org/external/2/272.pdf

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
    char str[100];
    int p = 0;

    while(scanf("%[^\n]", str) != EOF){
        getchar();
        
        for(int i=0; i<strlen(str); i++){
            if(str[i] == '"'){
                if(p){
                    printf("''");
                }
                else{
                    printf("``");
                }
                p ^= 1;
            }
            else{
                printf("%c", str[i]);
            }
        }

        printf("\n");
    }
}