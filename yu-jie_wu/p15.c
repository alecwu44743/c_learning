#include <stdio.h>
#include <stdlib.h>

int  which_is_bigger(int a, int b){
    if(a == b){
        return a;
    }
    else{
        return (a < b) ? b : a;
    }
}

int main(){
    int a, b;

    while(scanf("%d %d", &a, &b) != EOF){
        printf("%d is bigger.\n", which_is_bigger(a, b));
    }
}