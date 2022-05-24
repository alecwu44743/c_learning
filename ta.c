#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int deal(int n){
    int tmp=0;
    while(n!=0){
        n/=10;
        tmp++;
    }
    printf(" %d \n",tmp);
    return tmp > 10;
}

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)&& a!=0 && b!=0){
        int cnt=0;
        printf(" %d %d \n",deal(a),deal(b));
        if(deal(a)||deal(b)){
            printf("Out of scope.\n");
            continue;
        }

        int n=0;
        while (a!=0 || b!=0){
            n=a%10 + b%10 + n/10;
            if(n>9){
                cnt++;
            }
            a/=10;
            b/=10;
        }
        if(cnt == 0) printf("No carry operation.\n");
        else if(cnt == 1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n",cnt);
    }
}