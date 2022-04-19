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

long long int intReverse(long long int n){
    int _sum = 0;

    while(n > 0){
        _sum *= 10;
        _sum += n%10;
        n /= 10;
    }

    return _sum;
}

void pB(){
    int n;
    long long int num;
    long long int rev_n;

    scanf("%d", &n);
    for(int ss=0; ss<n; ss++){
        scanf("%lld", &num);

        rev_n = intReverse(num);

        if(rev_n == num){
            printf("%d %lld\n", 0, num);
        }
        else{
            int cnt = 0;

            while(rev_n != num){
                cnt++;
                num += rev_n;
                rev_n = intReverse(num);
            }
            printf("%d %lld\n", cnt, num);
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