#include <stdio.h>
#include <stdlib.h>

int main(){
    int ccase;
    int num;
    int happy;
    int isHappy = 0;
    
    while(scanf("%d", &ccase) != EOF){
        for(int cc = 1; cc<=ccase; cc++){
            scanf("%d", &num);

            int n = num;
            while(1){
                int _sum = 0;

                while(n){
                    _sum += (n%10) * (n%10);
                    n /= 10;
                }

                if(_sum == 1){
                    isHappy = 1;
                    break;
                }
                if(_sum < 10) break;

                n = _sum;
            }

            printf("Case #%d: %d is ", cc, num);
            printf("%s\n", (isHappy) ? "a Happy number." : "an Unhappy number.");

            isHappy = 0;
        }
    }
}