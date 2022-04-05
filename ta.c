#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

unsigned int fib[24][2] = { {1, 1} };
char BFSs [4][3] = {"0", "1", "01", "101"};

void init_fib(){
    for(int i=1; i<24; i++){
        fib[i][0] = fib[i-1][0] + fib[i-1][i];
        fib[i][1] = fib[i-1][1] + fib[i][0];
    }
}

int main(){
    long long int t, n, l, r, nowIndex, buffer;
    unsigned minus;

    fib_init();

    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &l, &r);

        if(n > 47) n = 46 + (n % 2);

        for(int i=l; i<=r; i++){
            nowIndex = i;
            buffer = n;

            while(buffer >= 4){
                minus = 0;

                if(buffer % 2){
                    if(nowIndex < fib[buffer / 2 - 1][1]){
                        buffer -= 2;
                        continue;
                    }
                    minus += fib[buffer / 2 - 1][1];
                }

                for(int j=0; j<2; j++){
                    if(nowIndex < minus + fib[buffer / 2 - 1][j]){
                        buffer = buffer - 2 - (buffer % 2) + j;
                        nowIndex -= minus;

                        break;
                    }

                    minus += fib[buffer / 2 - 1][j];
                }
            }

            printf("%c", BFSs[buffer][nowIndex]);
        }

        printf("\n");
    }
}
