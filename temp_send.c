#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

int main(){
    int nn;
    int n, k;
    int num[10004];
    int dp[10004][104];

    while(scanf("%d", &nn)){
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
}