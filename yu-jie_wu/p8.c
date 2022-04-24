#include <stdlib.h>
#include <stdio.h>

int main(){
    int a, b;

    while(scanf("%d %d", &a, &b) != EOF){
        if(a > b){
            int temp = a;
            a = b;
            b = temp;
        }

        for(int i=b; i>=a; i--){
            printf("%d ", i);
        }
        printf("\n");
    }
}