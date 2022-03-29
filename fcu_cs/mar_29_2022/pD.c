#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct sstudent{
    char name[25];
    int score;
    sex;
};
typedef struct sstudent sstudent;


int main(){
    sstudent st[4];
    int m_max;
    int m_max_val = -1;
    int f_max;
    int f_max_val = -1;
    int i = 0;

    while(scanf("%[^\t]", st[i].name) != EOF){
        scanf("%d %s\n", &st[i].score, st[i].sex);

        if(st[i].score > m_max_val && st[i].sex[0] == 'M'){
            m_max = i;
            m_max_val = st[i].score;
        }
        if(st[i].score > f_max_val && st[i].sex[0] == 'F'){
            f_max = i;
            f_max_val = st[i].score;
        }
        i++;
        // getchar();
    }

    printf("%s %d %s\n", st[f_max].name, st[f_max].score, st[f_max].sex);
    printf("%s %d %s\n", st[m_max].name, st[m_max].score, st[m_max].sex);
}