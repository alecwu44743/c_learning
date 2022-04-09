#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

enum Sex{
    Female,
    Male
};
typedef enum Sex Sex;

struct sstudent{
    char name[25];
    int score;
    Sex sex;
};
typedef struct sstudent sstudent;

int main(){
    sstudent st[4];
    char temp_sex[10];
    int m_max;
    int m_max_val = -1;
    int f_max;
    int f_max_val = -1;
    int i = 0;

    while(scanf("%[^\t]", st[i].name) != EOF){
        scanf("%d %s\n", &st[i].score, temp_sex);

        // if(temp_sex == Male){
        //     st[i].sex = Male;
        //     if(st[i].score > m_max_val){
        //         m_max = i;
        //         m_max_val = st[i].score;
        //     }
        // }
        // if(temp_sex == Female){
        //     st[i].sex = Female;
        //     if(st[i].score > f_max_val){
        //         m_max = i;
        //         m_max_val = st[i].score;
        //     }
        // }

        i++;
        // getchar();
    }

    printf("%s %d %s\n", st[f_max].name, st[f_max].score, "Femle");
    printf("%s %d %s\n", st[m_max].name, st[m_max].score, "Male");
}