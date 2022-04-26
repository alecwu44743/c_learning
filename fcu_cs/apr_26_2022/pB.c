// UVa 397: Equation Elation
// https://vjudge.net/problem/UVA-397

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

char str[1000];
int nums[100];
char ops[100];
char var[100];

int isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int isNumber(char c){
    return c >= '0' && c <= '9';
}


int main(){
    while(scanf("%[^\n]", str) != EOF){
        getchar();

        int index = 0;
        int status = 0;
        int num = 0;
        int num_sign = 1;
        for(int i=0; i<strlen(str); i++){
            if(status == 0){
                if(str[i] == '+' || str[i] == '-' || isNumber(str[i])){
                    status = 1;
                    if(str[i] == '-'){
                        num_sign = -1;
                    }
                    else if(str[i] == '+'){
                        num_sign = +1;
                    }
                    else{
                        num = str[i] - '0';
                    }
                }
            }
            else if(status == 1){
                if(str[i] == ' ' || str[i] == '=' || isOperator(str[i])){
                    nums[index] = num * num_sign;
                    num_sign = +1;
                    num = 0;
                    if(isOperator(str[i])){
                        ops[index++] = str[i];
                        status = 0;
                    }
                    else if(str[i] == '='){
                        ops[index++] = str[i];
                        status = 3;
                    }
                    else{
                        status = 2;
                    }
                }
                else{
                    num = num*10 + str[i]-'0';
                }
            }
            else if(status == 2){
                ops[index++] = str[i];
                if(isOperator(str[i])){
                    status = 0;
                }
                else if(str[i] == '='){
                    status = 3;
                }
            }
            else if(status == 3){
                if(str[i] != ' '){
                    strcpy(var, &str[i]);
                    while(var[strlen(var)-1] == ' '){
                        var[strlen(var)-1] = 0;
                    }

                    break;
                }
            }
        }

        for(int i=0; i<index; i++){
            for(int j=i; j<index-1; j++){
                printf("%d %c ", nums[j], ops[j]);
            }

            printf("%d = %s\n", nums[index-1], var);

            int space = i;
            for(int j = index-1; j>=i; j--){
                if(ops[j] == '*' || ops[j] == '/'){
                    space = j;
                }
            }

            if(ops[space] == '+'){
                nums[space+1] = nums[space] + nums[space+1];
            }
            else if(ops[space] == '-'){
                nums[space+1] = nums[space] - nums[space+1];
            }
            else if(ops[space] == '*'){
                nums[space+1] = nums[space] * nums[space+1];
            }
            else if(ops[space] == '/'){
                nums[space+1] = nums[space] / nums[space+1];
            }

            for(int j=space; j>=i; j--){
                nums[j] = nums[j-1];
                ops[j] = ops[j-1];
            }
        }

        printf("\n");
    }
}