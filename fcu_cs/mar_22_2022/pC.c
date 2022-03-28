#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){

    int n;

    scanf("%d", &n);
    char str[256];

    for(int ss=0; ss<n; ss++){
        scanf("%s", str);
        
        char c;
        int cnt = 0;
        for(int i=0; i<strlen(str); i++){
            if(isalpha(str[i])){
                c = str[i];
            }
            else{
                cnt *= 10;
                cnt += str[i] - '0';

                if(isalpha(str[i+1]) || i+1 == strlen(str)){
                    for(int j=0; j<cnt; j++){
                        printf("%c", c);
                    }
                    cnt = 0;
                }
            }
        }

        printf("\n");
    }
}

