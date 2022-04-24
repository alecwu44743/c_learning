#include <stdio.h>
#include <stdlib.h>

int main(){
    int data[3];

    for(int i=0; i<3; i++) scanf("%d", &data[i]);

    // bubble sort
    for(int i=0; i<3; i++){
        for(int j=0; j<3-i-1; j++){
            if(data[j] > data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }

    for(int i=0; i<3; i++) printf("%d ", data[i]);

    printf("\n");
}