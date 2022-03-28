#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
    int nn;
    int n, k;
    int num[100];
    int dp[1000][1000];

    scanf("%d", &nn);
        for(int ii=0; ii<nn; ii++){
            scanf("%d %d", &n, &k);

            for(int i=0; i<n; i++){
                scanf("%d", &num[i]);
                num[i] = abs(num[i]) % k;
            }

            memset(dp, 0, sizeof(dp)), dp[0][0] = 1;
            for(int i=0; i<n; i++){
                for(int j=0; j<k; j++){
                    if(dp[i][j]){
                        dp[i+1][(j+num[i]+k) % k] = 1;
                        dp[i+1][(j-num[i]+k) % k] = 1;
                    }
                }
            }

            if(dp[n][0]){
                printf("Divisible\n");
            }
            else{
                printf("Not divisible\n");
            }
        }
}