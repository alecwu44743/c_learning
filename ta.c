#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<limits.h>

void find_max(int arr[], int n, int *_max){
    int max = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    *_max = max;
}

int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int largest;

    find_max(arr, 10, &largest);
    printf("%d\n", largest);
}