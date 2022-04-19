#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y){
    int n = x*y;
    while(y != 0){
        int t = y;
        y = x%y;
        x = t;
    }

    return x;
}


int main(){
    int g, n;

    while(scanf("%d", &n)){
        if(n == 0) break;

        g = 0;
        for(int i=1; i<n; i++){
            for(int j=i+1; j<=n; j++){
                g += gcd(i, j);
            }
        }

        printf("%d\n", g);
    }
}