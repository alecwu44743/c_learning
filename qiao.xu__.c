#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int main(){

    char str[1000];

    printf("Please enter blablabla....: ");
    while(scanf("%[^\n]", str) != EOF){
        getchar();

        for(int i=0; i<strlen(str); i++){
            printf("%c ", str[i]);
        }
        printf("\n");

        int pass = 0;
        for(int i=strlen(str)-1; i>=0; i--){
            for(int j=0; j<strlen(str)-1-i; j++){
                if(str[j] > str[j+1]){
                    char tmp = str[j];
                    str[j] = str[j+1];
                    str[j+1] = tmp;

                    pass++;
                    printf("%2d pass =>", pass);
                    for(int k=0; k<strlen(str); k++){
                        printf("%c ", str[k]);
                    }
                    printf("\n");
                }
            }
        }

        printf("Please enter blablabla....: ");
    }

}