#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(){
    int n;
    char str[100];

    while(scanf("%d", &n) != EOF){
        for(int cnt=0; cnt<n; cnt++){
            scanf("%s", str);
            
            char stack[100];
            int top = 0;
            int isValid = 1;

            for(int i=0; i<strlen(str); i++){
                if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                    stack[top] = str[i];
                    top++;
                }
                else if(str[i] == ')'){
                    if(top == 0 || stack[top-1] != '('){
                        isValid = 0;
                        break;
                    }
                    else{
                        top--;
                    }
                }
                else if(str[i] == ']'){
                    if(top == 0 || stack[top-1] != '[' ){
                        isValid = 0;
                        break;
                    }
                    else{
                        top--;
                    }
                }
                else if(str[i] == '}'){
                    if(top == 0 || stack[top-1] != '{'){
                        isValid = 0;
                        break;
                    }
                    else{
                        top--;
                    }
                }

                if(top > 1){
                    char up = stack[top-1]; top--;
                    char dn = stack[top-1]; top--;

                    if((up - '0') > (dn - '0')){
                        isValid = 0;
                        break;
                    }
                    else{
                        stack[top++] = dn;
                        stack[top++] = up;
                    }
                }
            }

            if(isValid == 1 && top == 0){
                printf("correct\n");
            }
            else{
                printf("wrong\n");
            }
        }
    }
}