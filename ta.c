#include<stdio.h>

int main(void){
    long long int v1, d1, v2, d2, count=1;

    while(1){
        scanf("%lld%lld%lld%lld", &v1, &d1, &v2, &d2);
        if(d1==d2 && v1==v2 && d1==v1 && d1==0) break;
        if(d1/v1 < d2/v2)   printf("Case #ll%d: You owe me a beer!\n", count);
        else    printf("Case #%lld: No beer for the captain.\n", count);
        long long int a=d1*v2+d2*v1, b=2*v1*v2, A=a, B=b, x;
        if(a%b == 0){
            printf("Avg. arrival time: %lld\n", a/b);
        }else {
            while(A>0 && B>0){
                if(A>b) A=A%B;
                else    B=B%A;
            }
            if(A==0)    x=B;
            else x=A;
            printf("Avg. arrival time: %lld/%lld\n", a/x, b/x);
        }
        count++;
    }
}