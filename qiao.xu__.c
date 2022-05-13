#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define N 4

int f1Arr[N+1];
int f2Arr[N+1];


void arrMultipl(){
    int ans[2*N+1] = {0};

    for(int i=0; i<N+1; i++){
        for(int j=0; j<N+1; j++){
            ans[i+j] += f1Arr[i] * f2Arr[j]; 
        }
    }

    printf("f1 * f2 = %d^%d", ans[N*2], N*2);
    for(int i=N*2-1; i>0; i--){
        if(ans[i] >= 0){
            printf(" + %dx^%d", ans[i], i);
        }
        else{
            printf(" - %dx^%d", abs(ans[i]), i);
        }
    }
    if(ans[0] >= 0){
        printf(" + %d\n", ans[0]);
    }
    else{
        printf(" - %d\n", abs(ans[0]));
    }
}

int main(){

    char str[9];

    while(1){
        printf("Please enter blablabla...: ");

        if(scanf("%s", str) == EOF){
            break;
        }
        printf("This is student ID: %s... midterm exam blablabla...\n", str);
        
        printf("Please enter f1(x) blablabla...: n=4: ");
        for(int i=0; i<N; i++){
            scanf("%d", &f1Arr[i]);
            getchar();
            getchar();
        }
        scanf("%d", &f1Arr[4]);

        printf("Please enter f2(x) blablabla...: n=4: ");
        for(int i=0; i<N; i++){
            scanf("%d", &f2Arr[i]);
            getchar();
            getchar();
        }
        scanf("%d", &f2Arr[4]);

        printf("F1(x)= %dx^%d", f1Arr[4], N);
        for(int i=N-1; i>0; i--){
            if(f1Arr[i] >= 0){
                printf(" + %dx^%d", f1Arr[i], i);
            }
            else{
                printf(" - %dx^%d", abs(f1Arr[i]), i);
            }
        }
        if(f1Arr[0] >= 0){
            printf(" + %d", f1Arr[0]);
        }
        else{
            printf(" - %d", abs(f1Arr[0]));
        }
        printf("\n");

        printf("F2(x)= %dx^%d", f2Arr[4], N);
        for(int i=N-1; i>0; i--){
            if(f2Arr[i] >= 0){
                printf(" + %dx^%d", f2Arr[i], i);
            }
            else{
                printf(" - %dx^%d", abs(f2Arr[i]), i);
            }
        }
        if(f2Arr[0] >= 0){
            printf(" + %d", f2Arr[0]);
        }
        else{
            printf(" - %d", abs(f2Arr[0]));
        }
        printf("\n");


        arrMultipl();
    }

}