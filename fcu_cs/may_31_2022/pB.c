// UVA12820 Cool Word - CPE
// https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/12820.pdf

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
    int ccase;
    int cc = 0;
    while(scanf("%d", &ccase) != EOF){
        char str[10000];
        int cool = 0;

        for(int c=0; c<ccase; c++){
            scanf("%s", str);

            int cnt[10000] = {0};
            int alpha[26] = {0};
            for(int i=0; i<strlen(str); i++){
                alpha[toupper(str[i]) - 'A']++;
            }

            for(int i=0; i<26; i++){
                if(alpha[i] != 0 && (cnt[alpha[i]] == 1 || alpha[i] == strlen(str))){
                    cool--;
                    break;
                }
                
                cnt[alpha[i]] = 1;
            }

            cool++;
        }
        cc++;
        printf("Case %d: %d\n", cc, cool);
    }
}