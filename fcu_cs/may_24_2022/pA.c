// UVA10035 - Primary Arithmetic
// https://zerojudge.tw/ShowProblem?problemid=c014

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
    char x[12];
    char y[12];

    while(scanf("%s %s", x, y) != EOF){
        if(strcmp(x, "0") == 0 && strcmp(y, "0") == 0) break;
        if(strlen(x) > 10 || strlen(y) > 10){
            printf("Out of scope.\n");
            continue;
        }

        int carry = 0;
        int buffer = 0;
        for(int i=strlen(x)-1, j=strlen(y)-1; i>=0 || j>=0; i--, j--){
            int x_val = (i>=0) ? x[i] - '0' : 0;
            int y_val = (j>=0) ? y[j] - '0' : 0;

            int sum = x_val + y_val + carry;
            buffer = 0;
            if(sum >= 10){
                carry++;
                buffer = sum/10;
            }

            // printf("sum = %d, carry = %d, buffer = %d\n", sum, carry, buffer);
        }
        
        if (carry == 0){
            printf("No carry operation.\n");
        }
        else if (carry == 1){
            printf("1 carry operation.\n");
        }
        else{
            printf("%d carry operations.\n", carry);
        }
    }
}