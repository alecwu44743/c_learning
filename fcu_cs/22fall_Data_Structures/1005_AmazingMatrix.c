#include <stdio.h>
#include <stdlib.h>

int mx[7][7];
int temp_mx[7][7];
int tempAs[7][7];
int n;

int checkSymmetric() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mx[i][j] != temp_mx[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

int checkAsymmetric(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mx[i][j] != tempAs[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

int checkMagicSquare(){
    int tl2br = 0;
    int tr2bl = 0;
    
    for(int i=0; i<n; i++){
        tl2br += mx[i][i];
        tr2bl += mx[i][n-i-1];
    }

    if(tl2br != tr2bl){
        return 0;
    }

    for(int i=0; i<n; i++){
        int row = 0;
        int col = 0;
        for(int j=0; j<n; j++){
            row += mx[i][j];
            col += mx[j][i];
        }
        if(row != tl2br || col != tl2br){
            return 0;
        }
    }

    return 1;
}

int main(){
    // while(scanf("%d", &n) != EOF){
        scanf("%d", &n);
        int numbers[n*n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                scanf("%d", &mx[i][j]);

                if(1 <= mx[i][j] && mx[i][j] <= n*n){
                    numbers[mx[i][j]-1] = 1;
                }

                temp_mx[j][i] = mx[i][j];
                tempAs[n-1-j][n-1-i] = mx[i][j];
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         printf("%d ", tempAs[i][j]);
        //     }
        //     printf("\n");
        // }

        int p = 0;

        if(checkSymmetric()){
            printf("Symmetric");
            p = 1;
        }
        if(checkAsymmetric()){
            if(p == 1) printf(" ");

            printf("Asymmetric");
            p = 1;
        }

        int notMaghic = 0;
        for(int i=0; i<n*n; i++){
            if(numbers[i] == 0){
                notMaghic = 1;
                break;
            }
        }

        if(checkMagicSquare() && notMaghic == 0){
            if(p == 1) printf(" ");

            printf("Magic Square");
            p = 1;
        }

        if(p == 0){
            printf("NOTHING");
        }


        printf("\n");
    // }
}