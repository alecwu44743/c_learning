#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int check(int arr[], int i, int sum, int *N, int *K){
    if(i == *N) return abs(sum) % (*K);

    if(check(arr, i+1, sum+arr[i], N, K) == 0) return 0;
    if(check(arr, i+1, sum-arr[i], N, K) == 0) return 0;

    return 1;        
}

int main(){
    int nn;
    int n, k;
    int arr[100];

    scanf("%d", &nn);
    for(int ii=0; ii<nn; ii++){
        scanf("%d %d", &n, &k);
        
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);

        if(check(arr, 0, 0, &n, &k) == 0) printf("Divisible\n");
        else printf("Not divisible\n");
    }
}