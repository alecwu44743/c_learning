#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


char writeFile[100];
char readFile[100];

char writeFilename[100];
char readFilename[100];

int matrix_amount = 0;
struct matrix{
    char name[10];
    int row;
    int col;
    double *data;
    int deleted;
};
typedef struct matrix matrix;

matrix mx[100];


void read_the_file(char *filename){
    FILE *fp;
    char buffer[100];

    fp = fopen(filename, "r");

    if(fp == NULL){
        printf("Error "); // *TODO: change the error message
        return;
    }
    else{
        int setMatrixName = 1;
        int setRow = 1;
        int setCol = 1;
        
        int index = 0;
        int n = 100;
        char tempName[10] = "";

        double num = 0;

        while(fgets(buffer, n, fp) != NULL){
            // for(int i=0; i<strlen(buffer); i++){
            //     printf("%c", buffer[i]);
            // }
            // printf("\n");

            
            // read the text file and store to the array
            for(int i=0; i<strlen(buffer); i++){
                char c = buffer[i];
                if(iscntrl(c) || c == ' '){
                    continue;
                }
                if(c == '#') break;

                if(isalpha(c)){
                    strncat(tempName, &c, 1);
                }
                else{
                    if(setMatrixName == 1){
                        strcpy(mx[matrix_amount].name, tempName);
                        strcpy(tempName, "");
                        setMatrixName = 0;
                        mx[matrix_amount].deleted = 0;
                    }

                    if(setRow == 1 || setCol == 1){
                        if(setRow == 1){
                            num = num*10 + (c - '0');

                            if(buffer[i+1] == ' ' || iscntrl(buffer[i+1])){
                                mx[matrix_amount].row = num;
                                num = 0;
                                setRow = 0;
                            }
                        }
                        else{
                            num = num*10 + (c - '0');

                            if(buffer[i+1] == ' ' || iscntrl(buffer[i+1])){
                                mx[matrix_amount].col = num;
                                num = 0;
                                setCol = 0;

                                mx[matrix_amount].data = malloc(sizeof(double)*mx[matrix_amount].row*mx[matrix_amount].col);
                            }
                        }
                    }
                    else{ // matrix elements
                        num = num*10 + (c - '0');

                        if(buffer[i+1] == ' ' || iscntrl(buffer[i+1])){
                            mx[matrix_amount].data[index] = num;
                            num = 0;
                            index++;
                        }
                    }

                    if(setRow == 0 && setCol == 0 && index == mx[matrix_amount].row*mx[matrix_amount].col){
                        matrix_amount++;
                        setMatrixName = 1;
                        setRow = 1;
                        setCol = 1;
                        index = 0;
                    }
                }
            }
        }

        fclose(fp);
    }
}


void print_all_matrix(){
    for(int i=0; i<matrix_amount; i++){
        printf("%s\n", mx[i].name);
        printf("%d %d\n", mx[i].row, mx[i].col);
        for(int j=0; j<mx[i].row; j++){
            for(int k=0; k<mx[i].col; k++){
                printf("%lf ", mx[i].data[j*mx[i].col + k]);
            }
            printf("\n");
        }
    }
}


void print_all_matrix_status(){
    printf("Matrixes status: \n");
    printf("Name    rows    cols\n");
    for(int i=0; i<matrix_amount; i++){
        printf(" %-6s %-7d %d\n", mx[i].name, mx[i].row, mx[i].col);
    }
}





int main(){
    char op[5];

    while(scanf("%s", op)){
        if(!strcmp(op,"!!q")){
            return 0;
        }

        if(!strcmp(op,"<")){
            scanf("%s", readFilename);
            read_the_file(readFilename);
            // print_all_matrix();
        }
        else if(!strcmp(op,"?")){
            print_all_matrix_status();
        }
    }

}
