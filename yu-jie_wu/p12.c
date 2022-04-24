#include <stdlib.h>
#include <stdio.h>

int main(){
    int n;

    while(scanf("%d", &n) != EOF){
        int _sum = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                _sum += j;
            }
        }

        printf("sum = %d\n", _sum);
    }
}