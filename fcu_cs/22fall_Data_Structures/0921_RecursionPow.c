#include <stdlib.h>
#include <stdio.h>
// #include <time.h>

int binaryExponentiation(int a, int b){
    if(b == 0){
        return 1;
    }
    else if(b % 2 == 1){
        return binaryExponentiation(a, b/2) * binaryExponentiation(a, b/2) * a;
    }
    else{
        return binaryExponentiation(a, b/2) * binaryExponentiation(a, b/2);
    }
}


int main(){
    int base, p;

    while(scanf("%d %d", &base, &p) != EOF){
        printf("%d\n", binaryExponentiation(base, p));
    }
}