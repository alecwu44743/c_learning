#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int ans_n;
int test_n;
char ans_str[100][150];
char test_str[100][150];

int judge_checkAC(){
    for(int i=0; i<ans_n; i++){
        for(int j=0; j<strlen(ans_str[i]); j++){
            if(ans_str[i][j] != test_str[i][j] || strlen(ans_str[i]) != strlen(test_str[i])){
                return 0;
            }
        }
    }

    return 1;
}

int judge_checkPE(){
    char pe_ans[ans_n*100+1];
    char pe_test[test_n*100+1];
    int ans_index = 0;
    int test_index = 0;

    for(int i=0; i<ans_n; i++){
        for(int j=0; ans_str[i][j]!='\0'; j++){
            if(!iscntrl(ans_str[i][j]) && !isspace(ans_str[i][j])){
                pe_ans[ans_index] = ans_str[i][j];
                ans_index++;
            }
        }
    }
    pe_ans[ans_index] = '\0';

    for(int i=0; i<test_n; i++){
        for(int j=0; test_str[i][j]!='\0'; j++){
            if(!iscntrl(test_str[i][j]) && !isspace(test_str[i][j])){
                pe_test[test_index] = test_str[i][j];
                test_index++;
            }
        }
    }
    pe_test[test_index] = '\0';

    return strcmp(pe_ans, pe_test) == 0;
}

int main(){
    int ccase = 1;

    while(scanf("%d", &ans_n) != EOF){
        if(ans_n == 0) break;

        int ans_strlen = 0;

        for(int i=0; i<ans_n; i++){
            getchar();
            scanf("%[^\n]", ans_str[i]);
            ans_strlen += strlen(ans_str[i]);
        }

        scanf("%d", &test_n);
        for(int i=0; i<test_n; i++){
            getchar();
            scanf("%[^\n]", test_str[i]);
        }


        printf("Run #%d: ", ccase);
        if(judge_checkAC()){
            printf("Accepted ");
        }
        else if(judge_checkPE()){
            printf("Presentation Error ");
        }
        else{
            printf("Wrong Answer ");
        }
        printf("%d\n", ans_strlen);

        ccase++;
    }
}