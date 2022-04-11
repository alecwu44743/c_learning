#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0) break;

        int arr_alpha[26] = {0};
        int max_cnt = -1;
        char str[100];
        char c;
        for(int ss=0; ss<n; ss++){
            getchar();
            scanf("%[^\n]", str);

            for(int idx=0; idx<strlen(str); idx++){
                c = str[idx];

                if(isalpha(c)){
                    arr_alpha[toupper(c) - 'A']++;

                    if(arr_alpha[toupper(c) - 'A'] > max_cnt) max_cnt = arr_alpha[toupper(c) - 'A'];
                }
            }
        }

        for(int cnt = max_cnt; cnt > 0; cnt--){
            for(int i=0; i<26; i++){
                if(arr_alpha[i] == cnt){
                    printf("%c %d\n", 'A'+i, cnt);
                }
            }
        }
        
    }
}