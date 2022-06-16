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

    if(matrix_amount == 0){
        printf("No matrixes\n");
    }

    for(int i=0; i<matrix_amount; i++){
        if(mx[i].deleted == 0){
            printf(" %-6s %-7d %d\n", mx[i].name, mx[i].row, mx[i].col);
        }
    }
}


void write_all_matrix(char *filename){
    FILE *fp;
    fp = fopen(filename, "w");

    if(fp == NULL){
        printf("Error "); // *TODO: change the error message
        return;
    }
    else{
        for(int i=0; i<matrix_amount; i++){
            if(mx[i].deleted == 0){
                fprintf(fp, "%s\n", mx[i].name);
                fprintf(fp, "%d %d\n", mx[i].row, mx[i].col);
                for(int j=0; j<mx[i].row; j++){
                    for(int k=0; k<mx[i].col; k++){
                        fprintf(fp, "%lf ", mx[i].data[j*mx[i].col + k]);
                    }
                    fprintf(fp, "\n");
                }
            }
        }
        fclose(fp);
    }
}


void delete_all_matrices(){
    for(int i=0; i<matrix_amount; i++){
        if(mx[i].deleted == 0){
            free(mx[i].data);
            strcpy(mx[i].name, "");
            mx[i].deleted = 1;
        }
    }

    matrix_amount = 0;
}


void print_a_matrix(char *name){
    for(int i=0; i<matrix_amount; i++){
        if(strcmp(mx[i].name, name) == 0 && mx[i].deleted == 0){
            printf("%s", mx[i].name);
            printf(" %d %d\n", mx[i].row, mx[i].col);
            for(int j=0; j<mx[i].row; j++){
                for(int k=0; k<mx[i].col; k++){
                    printf("%lf ", mx[i].data[j*mx[i].col + k]); // *TODO : change the format
                }
                printf("\n");
            }
            return;
        }
    }
    printf("Matrix not found QQ.\n");
}


void delete_a_matrix(char *name){
    for(int i=0; i<matrix_amount; i++){
        if(strcmp(mx[i].name, name) == 0 && mx[i].deleted == 0){
            free(mx[i].data);
            mx[i].deleted = 1;
            return;
        }
    }
    printf("Matrix not found QQ.\n");
}


void add_a_matrix(char resArr, char arr, int r, int rr, int c, int cc){
    int findmx = -1;

    for(int i=0; i<matrix_amount; i++){
        if(mx[i].name[0] == arr && mx[i].deleted == 0){
            findmx = i;
            break;
        }
    }

    if(r < 0 || c < 0 || rr > mx[findmx].row || cc > mx[findmx].col){
        printf("Error: invalid matrix index.\n");
        return;
    }

    if(findmx == -1){
        printf("Matrix not found QQ.\n");
        return;
    }

    int isResArrExist = -1;
    for(int i=0; i<matrix_amount; i++){
        if(mx[i].name[0] == resArr && mx[i].deleted == 0){
            isResArrExist = i;
            break;
        }
    }

    if(isResArrExist == -1){
        strncat(mx[matrix_amount].name, &resArr, 1);
        mx[matrix_amount].row = rr-r;
        mx[matrix_amount].col = cc-c;
        mx[matrix_amount].data = malloc(sizeof(double)*mx[matrix_amount].row*mx[matrix_amount].col);
        mx[matrix_amount].deleted = 0;

        for(int i=0; i<mx[matrix_amount].row; i++){
            for(int j=0; j<mx[matrix_amount].col; j++){
                mx[matrix_amount].data[i*mx[matrix_amount].col + j] = mx[findmx].data[(i+r)*mx[findmx].col + j+c];
            }
        }

        matrix_amount++;
    }
    else{
        mx[isResArrExist].data = malloc(sizeof(double)*(rr-r)*(cc-c));

        mx[isResArrExist].row = rr-r;
        mx[isResArrExist].col = cc-c;

        for(int i=0; i<mx[isResArrExist].row; i++){
            for(int j=0; j<mx[isResArrExist].col; j++){
                mx[isResArrExist].data[i*mx[isResArrExist].col + j] += mx[findmx].data[(i+r)*mx[findmx].col + j+c];
            }
        }
    }
}    


void plus_and_minus_matrix(char resArr, char opA, char opB, char op){
    int isResArrExist = -1;
    int isOpAExist = -1;
    int isOpBExist = -1;

    for(int i=0; i<matrix_amount; i++){
        if(mx[i].name[0] == resArr && mx[i].deleted == 0){
            isResArrExist = i;
        }

        if(mx[i].name[0] == opA && mx[i].deleted == 0){
            isOpAExist = i;
        }

        if(mx[i].name[0] == opB && mx[i].deleted == 0){
            isOpBExist = i;
        }

        if(isResArrExist != -1 && isOpAExist != -1 && isOpBExist != -1){
            break;
        }
    }

    if(isOpAExist == -1){
        printf("Matrix not found QQ.\n");
        return;
    }

    if(isOpBExist == -1){
        printf("Matrix not found QQ.\n");
        return;
    }

    if(mx[isOpAExist].row != mx[isOpBExist].row || mx[isOpAExist].col != mx[isOpBExist].col){
        printf("Matrix size not match QQ.\n");
        return;
    }

    if(isResArrExist == -1){
        strncat(mx[matrix_amount].name, &resArr, 1);
        mx[matrix_amount].row = mx[isOpAExist].row;
        mx[matrix_amount].col = mx[isOpBExist].col;
        mx[matrix_amount].data = malloc(sizeof(double)*mx[matrix_amount].row*mx[matrix_amount].col);
        mx[matrix_amount].deleted = 0;

        for(int i=0; i<mx[matrix_amount].row; i++){
            for(int j=0; j<mx[matrix_amount].col; j++){
                if(op == '+'){
                    mx[matrix_amount].data[i*mx[matrix_amount].col + j] = mx[isOpAExist].data[i*mx[isOpAExist].col + j] + mx[isOpBExist].data[i*mx[isOpBExist].col + j];
                }
                else if(op == '-'){
                    mx[matrix_amount].data[i*mx[matrix_amount].col + j] = mx[isOpAExist].data[i*mx[isOpAExist].col + j] - mx[isOpBExist].data[i*mx[isOpBExist].col + j];
                }
            }
        }

        matrix_amount++;
        return;
    }

    double *tempArr = malloc(sizeof(double)*mx[isOpAExist].row*mx[isOpAExist].col);

    if(op == '+'){
        for(int i=0; i<mx[isResArrExist].row; i++){
            for(int j=0; j<mx[isResArrExist].col; j++){
                tempArr[i*mx[isResArrExist].col + j] = mx[isOpAExist].data[i*mx[isOpAExist].col + j] + mx[isOpBExist].data[i*mx[isOpBExist].col + j];
            }
        }
    }
    else if(op == '-'){
        for(int i=0; i<mx[isResArrExist].row; i++){
            for(int j=0; j<mx[isResArrExist].col; j++){
                tempArr[i*mx[isResArrExist].col + j] = mx[isOpAExist].data[i*mx[isOpAExist].col + j] - mx[isOpBExist].data[i*mx[isOpBExist].col + j];
            }
        }
    }

    mx[isResArrExist].data = malloc(sizeof(double)*mx[isResArrExist].row*mx[isResArrExist].col);

    mx[isResArrExist].row = mx[isOpAExist].row;
    mx[isResArrExist].col = mx[isOpBExist].col;

    for(int i=0; i<mx[isResArrExist].row; i++){
        for(int j=0; j<mx[isResArrExist].col; j++){
            mx[isResArrExist].data[i*mx[isResArrExist].col + j] = tempArr[i*mx[isResArrExist].col + j];
        }
    }

    free(tempArr);
}


void be_minOrpls_matrix(char resArr, char opA, char op){
    int isOpAExist = -1;
    int isResArrExist = -1;

    for(int i=0; i<matrix_amount; i++){
        if(mx[i].name[0] == opA && mx[i].deleted == 0){
            isOpAExist = i;
        }

        if(mx[i].name[0] == resArr && mx[i].deleted == 0){
            isResArrExist = i;
        }

        if(isOpAExist != -1 && isResArrExist != -1) break;
    }
    if(isOpAExist == -1){
        printf("Matrix not found QQ.\n");
        return;
    }

    if(isResArrExist == -1){
        strncat(mx[matrix_amount].name, &resArr, 1);
        mx[matrix_amount].row = mx[isOpAExist].row;
        mx[matrix_amount].col = mx[isOpAExist].col;
        mx[matrix_amount].data = malloc(sizeof(double)*mx[matrix_amount].row*mx[matrix_amount].col);
        mx[matrix_amount].deleted = 0;

        if(op == '+'){
            for(int i=0; i<mx[matrix_amount].row; i++){
                for(int j=0; j<mx[matrix_amount].col; j++){
                    mx[matrix_amount].data[i*mx[matrix_amount].col + j] = mx[isOpAExist].data[i*mx[isOpAExist].col + j];
                }
            }
        }
        else if(op == '-'){
            for(int i=0; i<mx[matrix_amount].row; i++){
                for(int j=0; j<mx[matrix_amount].col; j++){
                    mx[matrix_amount].data[i*mx[matrix_amount].col + j] = -mx[isOpAExist].data[i*mx[isOpAExist].col + j];
                }
            }
        }

        matrix_amount++;
        return;
    }

    mx[isResArrExist].data = malloc(sizeof(double)*mx[isOpAExist].row*mx[isOpAExist].col);

    if(op == '-'){
        for(int i=0; i<mx[isResArrExist].row; i++){
            for(int j=0; j<mx[isResArrExist].col; j++){
                mx[isResArrExist].data[i*mx[isResArrExist].col + j] = -mx[isOpAExist].data[i*mx[isOpAExist].col + j];
            }
        }
    }
    else if(op == '+'){
        for(int i=0; i<mx[isResArrExist].row; i++){
            for(int j=0; j<mx[isResArrExist].col; j++){
                mx[isResArrExist].data[i*mx[isResArrExist].col + j] = mx[isOpAExist].data[i*mx[isOpAExist].col + j];
            }
        }
    }
}


void multiply_matrix(char resArr, char opA, char opB){
    int isOpAExist = -1;
    int isOpBExist = -1;
    int isResArrExist = -1;

    for(int i=0; i<matrix_amount; i++){
        if(mx[i].name[0] == opA && mx[i].deleted == 0){
            isOpAExist = i;
        }

        if(mx[i].name[0] == opB && mx[i].deleted == 0){
            isOpBExist = i;
        }

        if(mx[i].name[0] == resArr && mx[i].deleted == 0){
            isResArrExist = i;
        }

        if(isOpAExist != -1 && isOpBExist != -1 && isResArrExist != -1) break;
    }

    if(isOpAExist == -1 || isOpBExist == -1){
        printf("Matrix not found QQ.\n");
        return;
    }

    if(mx[isOpAExist].col != mx[isOpBExist].row){
        printf("Matrix not compatible QQ.\n");
        return;
    }

    if(isResArrExist == -1){
        strncat(mx[matrix_amount].name, &resArr, 1);
        mx[matrix_amount].row = mx[isOpAExist].row;
        mx[matrix_amount].col = mx[isOpBExist].col;
        // mx[matrix_amount].data = malloc(sizeof(double) * mx[matrix_amount].row * mx[matrix_amount].col);

        // for(int i=0; i<mx[matrix_amount].row; i++){
        //     for(int j=0; j<mx[matrix_amount].col; j++){
        //         double temp = 0;
        //         for(int k=0; k<mx[isOpAExist].col; k++){
        //             temp += mx[isOpAExist].data[i*mx[isOpAExist].col + k] * mx[isOpBExist].data[k*mx[isOpBExist].col + j];
        //         }
        //         mx[matrix_amount].data[i*mx[matrix_amount].col + j] = temp;
        //     }
        // }

        // printf("ccccc\n");

        // if(mx[matrix_amount].data == NULL){
        //     printf("Memory error QQ.\n");
        //     return;
        // }

        printf("aaaa\n");

        int r = 8, c = 5, i, j, count;
 
        double **arr = (double**)malloc(r * sizeof(double*) + r*c*sizeof(double));

        printf("ok");
            
        for(int i=0; i<mx[isOpAExist].row; i++){
            for(int j=0; j<mx[isOpBExist].col; j++){
                arr[i][j] = 0;
                for(int k=0; k<mx[isOpBExist].row; k++){
                    arr[i][j] += mx[isOpAExist].data[i*mx[isOpAExist].col + k] * mx[isOpBExist].data[k*mx[isOpBExist].col + j];
                }
            }
        }

        matrix_amount++;
        return;
    }

    double *tempArr = malloc(sizeof(double)*mx[isOpAExist].row*mx[isOpBExist].col);

    mx[isResArrExist].row = mx[isOpAExist].row;
    mx[isResArrExist].col = mx[isOpBExist].col;

    for(int i=0; i<mx[isResArrExist].row; i++){
        for(int j=0; j<mx[isOpBExist].col; j++){
            tempArr[i*mx[isOpBExist].col + j] = 0;
            for(int k=0; k<mx[isOpAExist].col; k++){
                tempArr[i*mx[isOpBExist].col + j] += mx[isOpAExist].data[i*mx[isOpAExist].col + k] * mx[isOpBExist].data[k*mx[isOpBExist].col + j];
            }
        }
    }

    for(int i=0; i<mx[isResArrExist].row; i++){
        for(int j=0; j<mx[isResArrExist].col; j++){
            mx[isResArrExist].data[i*mx[isResArrExist].col + j] = tempArr[i*mx[isResArrExist].col + j];
        }
    }


    free(tempArr);
}

int main(){
    char op[30];

    printf("$ ");

    while(scanf("%[^\n]", op) != EOF){
        getchar();
        if(!strcmp(op,"!!q")){
            delete_all_matrices();
            return 0;
        }

        if(op[0] == '<'){
            strcpy(readFilename, op+2);
            read_the_file(readFilename);
            // print_all_matrix();
        }
        else if(op[0] == '>'){
            strcpy(writeFilename, op+2);
            write_all_matrix(writeFilename);
        }
        else if(!strcmp(op,"?")){
            print_all_matrix_status();
        }
        else if(!strcmp(op,"!!d")){
            delete_all_matrices();
        }
        else if(op[0] == '?'){
            char to_print_mxName[10];
            strcpy(to_print_mxName, op+1);

            // printf("%s\n", to_print_mxName);
            print_a_matrix(to_print_mxName);
        } 
        else if(op[0] == '!'){
            char to_delete_mxName[10];
            strcpy(to_delete_mxName, op+1);

            delete_a_matrix(to_delete_mxName);
        }
        else{
            char *find_brackets = strstr(op, "[");
            char *find_equalSign = strstr(op, "=");

            if(find_brackets && find_equalSign){
                char resArr;
                char arr;
                int r, rr;
                int c, cc;

                sscanf(op, "%c=%c[%d:%d,%d:%d]", &resArr, &arr, &r, &rr, &c, &cc);

                // printf("%c\n", resArr);
                // printf("%c\n", arr);
                // printf("%d %d\n", r, rr);
                // printf("%d %d\n", c, cc);

                add_a_matrix(resArr, arr, r, rr, c, cc);
            }
            else if(find_equalSign){
                char resArr = '^';
                char operantA = '^';
                char operantB = '^';
                char operator = '^';

                for(int i=0; i<strlen(op); i++){
                    if(op[i] == '=' || op[i] == ' ' || iscntrl(op[i])){
                        continue;
                    }
                    else if(resArr == '^'){
                        resArr = op[i];
                    }
                    else if(operantA == '^'){
                        if(op[i] == '+' || op[i] == '-'){
                            operator = op[i];
                            operantA = '%';
                        }
                        else{
                            operantA = op[i];
                        }
                    }
                    else if(operator == '^'){
                        operator = op[i];
                    }
                    else if(operantB == '^'){
                        operantB = op[i];
                    }
                }

                printf("%c = %c %c %c\n", resArr, operantA, operator, operantB);
                
                if(operantA == '%'){
                    be_minOrpls_matrix(resArr, operantB, operator);
                }
                else if(operator == '+' || operator == '-'){
                    plus_and_minus_matrix(resArr, operantA, operantB, operator);
                }
                else if(operator == '*'){
                    multiply_matrix(resArr, operantA, operantB);
                }
            }
            else{
                printf("[x] Invalid command.\n");
            }
        }
        
        printf("$ ");
    }

}