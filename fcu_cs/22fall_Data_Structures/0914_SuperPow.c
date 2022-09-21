#include <stdlib.h>
#include <stdio.h>
// #include <time.h>


void normal_pow(int a, int b){
    // clock_t t1, t2;
    // t1 = clock();
    int cnt = 0;

    int result = 1;
    for(int i = 0; i < b; i++){
        result *= a;
        cnt++;
    }
    // t2 = clock();

    printf("Normal: %d\n", result);
    printf("Normal Count: %d\n", cnt);
    // printf("Time: %f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
}


void binaryExponentiation(int a, int b){
    // clock_t t1, t2;
    // t1 = clock();
    int cnt = 1;

    int result = 1;
    while(b > 0){
        cnt++;

        if(b % 2 == 1){
            result *= a;
            cnt++;
        }
        a *= a;
        b /= 2;
    }
    // t2 = clock();

    printf("Binary: %d\n", result);
    printf("Binary Count: %d\n", cnt);
    // printf("Time: %f\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
}


void lectureSol(int a, int b){
    int binNum[100];
    int index = 0;
    while(b > 0){
        binNum[index] = b % 2;
        b /= 2;
        index++;
    }

    int cnt = 0;
    int result = 1;
    for(int i=index-1; i>=0; i--){
        (binNum[i] == 1) ? (result *= result * a) : (result *= result);
        cnt++;
    }

    printf("Lecture: %d\n", result);
    printf("Lecture Count: %d\n", cnt);
}


int main(){
    int p;

    while(scanf("%d", &p) != EOF){
        // normal_pow(2, p);
        // binaryExponentiation(2, p);
        lectureSol(3, p);
    }
}