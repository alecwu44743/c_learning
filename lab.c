#include<stdio.h>
#include<string.h>

int main(){
    char str[200];

    while(scanf("%[^\n]s", str) != EOF){
        int cnt = 0;

        for(int i=0; i<strlen(str); i++){
            if(isalpha(str[i]) && !isalpha(str[i+1])){
                cnt++;
            }
        }

        printf("%d\n", cnt);
        getchar();
    }
}