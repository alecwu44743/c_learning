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
    int n;
    char str[256];
    char c;
    
    while(scanf("%d", &n) != EOF){
        

        for(int ss = 0; ss < n; ss++){
            scanf("%c", &c);
            scanf("%s", str);

            int llen = strlen(str);
            int i, j;

            for(i=1; i<llen; i++){
                for(j=0; j+i<llen; j++){
                    if(str[j] != str[j+i]) break;
                }
                if(i+j == llen) break;
            }

            if(llen % i != 0){
                printf("%d\n", llen);
            }
            else{
                printf("%d\n", i);
            }
        }
    }
}

// reference - https://yuihuang.com/uva-10642/
void pD(){
    int ccase = 0;
    long long int x, y, step1, step2;
    long long int n;

    while(scanf("%d", &ccase) != EOF){
        if(ccase == 0) break;

        for(int cc=1; cc<=ccase; cc++){
            scanf("%lld %lld", &x, &y);
            if(x ==0 && y==0){
                step1 = 0;
            }
            else{
                n = x + y - 1;
                step1 = (n*n + 3*n)/2 + (x + 1);
            }

            scanf("%lld %lld", &x, &y);
            if(x ==0 && y==0){
                step2 = 0;
            }
            else{
                n = x + y - 1;
                step2 = (n*n + 3*n)/2 + (x + 1);
            }
            
            printf("Case %d: %lld\n", cc, step2-step1);
        }
    }
}

int main(){
    // pA(); 
    // pB(); 
    // pC(); 
    // pD();
}