#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

char str[1000];
char var[100];
char op[100];
int num[100];

int number(char n){
    return n >= '0' && n<= '9';
}

int operator(char k){
    return k == '+' || k == '-' || k == '*' || k == '/';
}

int main(){
    while(scanf("%[^\n]",str) != EOF){
        getchar();
        int index = 0;
        int ccase = 0;
        int num = 0;
        int sign = 1;
        for(int i=0;i<strlen(str);i++){
            if(ccase == 0){
                if(str[i] == '+' || str[i] == '-' || number(str[i])){
                    ccase = 1;
                    if(str[i] == '+'){
                        sign = 1;
                    }
                    else if(str[i] == '-'){
                        sign = -1;
                    }
                    else{
                        num = str[i] - '0';
                    }
                }
            }
            else if(ccase == 1){
                if(str[i] == ' ' || str[i] == '=' || operator(str[i])){
                    // num[index] = num*sign; - error  
                    sign = 1;
                    num = 0;
                    if(str[i] == ' '){
                        ccase = 0;
                    }
                    else if(str[i] == '='){
                        
                    }
                    else{
                        ccase = 2;
                    }
                }
            }
        }
    }
}