#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct student{
    char name[10];
    int score;
};
typedef struct student student;

void compare_student(student *st, int index){
    for(int i=0; i<index; i++){
        
        for(int j=i+1; j<index; j++){
            if(st[i].score > st[j].score){
                student temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
}

int main(){

    int index = 0;
    student st[100];
    while(scanf("%s %d", st[index].name, &st[index].score) != EOF){
        index++;
    }

    compare_student(st, index);

    for(int i=0; i<index; i++){
        printf("%s %d\n", st[i].name, st[i].score);
    }
}

