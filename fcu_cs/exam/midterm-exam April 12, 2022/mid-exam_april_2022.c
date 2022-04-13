#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

void pA(){
    int n;
    while(scanf("%d", &n)){
        char c;
        char str[100];
        int alpha[26] = {0};

        for(int ss=0; ss<n; ss++){
            getchar();
            scanf("%[^\n]", str);

            for(int i=0; i<strlen(str); i++){
                c = str[i];
                alpha[toupper(c) - 'A']++;
            }
        }

        for(int i=0; i<26; i++){
            if(alpha[i] > 0){
                printf("%c %d\n", i+'A', alpha[i]);
            }
        }
    }
}

long long int pB_pal(long long int n){
    int _sum = 0;
    while(n){
        _sum *= 10;
        _sum += n%10;
        n/=10;
    }

    return _sum;
}

void pB(){
    int num;
    long long int n;

    while(scanf("%d", &num)){
        for(int ss=0; ss<num; ss++){
            int cnt = 0;
            long long int rev;

            scanf("%lld", &n);
            
            rev = pB_pal(n);
            do{
                n += rev;
                cnt++;
                rev = pB_pal(n);
            }while(n != rev);

            printf("%d %lld\n", cnt, n);
        }
    }
}

void pC(){

}

void pD(){

}

int main(){
    // pA(); 
    pB(); 
    // pC(); 
    // pD();
}