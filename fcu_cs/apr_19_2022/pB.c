// UVa 11417: GCD 
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2412

#include <stdio.h>
#include <stdlib.h>

// reference - https://www.csie.ntu.edu.tw/~b98902112/cpp_and_algo/cpp02/euclidean_algorithm.html
int gcd(int x, int y){
    // int n = x*y;
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