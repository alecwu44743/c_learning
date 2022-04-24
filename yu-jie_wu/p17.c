#include <stdlib.h>
#include <stdio.h>

int main(){
    char c;

    while(scanf("%c", &c) != EOF){
        if('a' <= c && c <= 'z'){
            c = c - 'a' + 'A';
        }

        printf("%c\n", c);
    }
}