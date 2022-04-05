#include <stdio.h>

struct student{
    char name[25];
    int score;
    char sex[20];
};

int main(){
    struct student s[10];
    int M, F, Mmax=-1, Fmax=-1;

    for(int i=0; scanf("%[^\t]", s[i].name) != EOF; i++){
        scanf("%d%s\n", &s[i].score, s[i].sex);

        if(s[i].score > Fmax && s[i].sex[0] == 'M'){
            F = i;
            Fmax = s[i].score;
        }
        else if(s[i].score > Mmax && s[i].sex[0] == 'F'){
            M = i;
            Mmax = s[i].score;
        }
    }

    printf("%s %d %s\n", s[F].name, s[F].score, s[F].sex);
    printf("%s %d %s\n", s[M].name, s[M].score, s[M].sex);
}