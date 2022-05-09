#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int bubble_sort(char *str){
    int pass = 0;

    for(int i=0; i<strlen(str); i++){
        for(int j=0; j<strlen(str)-1-i; j++){
            if(str[j] > str[j+1]){
                char tmp = str[j];
                str[j] = str[j+1];
                str[j+1] = tmp;

                pass++;
                printf("%-2d pass =>", pass);
                for(int k=0; k<strlen(str); k++){
                    printf("%c ", str[k]);
                }
                printf("\n");
            }
        }
    }

    return pass;
}


int main(){

    char str[1000];

    printf("Please enter blablabla....: ");
    while(scanf("%[^\n]", str) != EOF){
        getchar();

        for(int i=0; i<strlen(str); i++){
            printf("%c ", str[i]);
        }
        printf("\n");

        int ps = bubble_sort(str);
        printf("%d\n", ps);

        printf("Please enter blablabla....: ");
    }

}