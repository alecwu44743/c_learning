#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

void guess(char ans){
    char input;

    while(scanf("%c", &input)){
             
        if(input < ans){
            printf("%s\n", "TOO SMALL!");
        }
        else if(input > ans){
            printf("%s\n", "TOO BIG!");
        }
        else{
            printf("%s\n", "GOOD!");
            break;
        }
        getchar();
    }
}

int main(){
    char str[4] = {'C', 'D', 'H', 'S'};
    int i = rand()%4;

    guess(str[i]);
}