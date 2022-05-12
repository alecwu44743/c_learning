#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
    char str[1005];

    while(scanf("%s", str) != EOF){
        for(int i=0; i<strlen(str); i++){
            char *start = str+i;
            char *end;

            while(*start != '\0'){
                printf("%c", *start);
                start++;
            }

            end = str+i;
            start = str;

            while(start!=end && str!='\0'){
                printf("%c", *start);
                start++;
            }

            printf("\n");
        }
    }
}