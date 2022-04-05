#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

long long int intReverse(long long int n){
    int _sum = 0;

    while(n > 0){
        _sum *= 10;
        _sum += n%10;
        n /= 10;
    }

    return _sum;
}

int main(){
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