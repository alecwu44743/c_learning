// 11054 - Wine trading in Gergovia
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1995

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main(){
    int n;
    int inhabitants[100000];
    while(scanf("%d",&n) && n != 0){
        for(int i=0; i<n; i++){
            scanf("%d", &inhabitants[i]);
        }

        long long int ans = 0;
        for(int i=0; i<n-1; i++){
            ans += abs(inhabitants[i]);
            inhabitants[i+1] += inhabitants[i];
        }

        printf("%lld\n",ans);
    }
}