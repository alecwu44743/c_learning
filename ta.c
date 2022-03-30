#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


char std[100][125];
char input[100][125];
int n,m;

int flag(){
    for(int i=0;i<n;i++){
        for(int j=0;j<strlen(std[i]);j++){
            if(std[i][j] != input[i][j] || strlen(std[i]) != strlen(input[i])){
                return 0;
            }
        }
    }
    return 1;
}

int judge(){
    char re_std[150];
    int r_s = 0;
    char re_input[150];
    int r_i = 0;
        
    /*std part*/
    for(int i=0;i<n;i++){
        for(int j=0;std[i][j] != '\0';j++){
            if(!iscntrl(std[i][j]) && !isspace(std[i][j])){
                re_std[r_s] = std[i][j];
                r_s++;
            }
        }
    }
    re_std[r_s] = '\0';
    /*input part*/
    for(int i=0;i<m;i++){
        for(int j=0;input[i][j] != '\0';j++){
            if(!iscntrl(input[i][j]) && !isspace(input[i][j])){
                re_input[r_i] = input[i][j];
                r_i++;
            }
        }
    }
    re_input[r_i] = '\0';
    return strcmp(re_std,re_input) == 0;
}

int main(){
    int times=1;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;
        int add = 0;
        for(int i=0;i<n;i++){
            getchar();
            scanf("%[^\n]",std[i]);
            add += strlen(std[i]);
            
        }

        scanf("%d",&m);
        
        for(int j=0;j<m;j++){
            getchar();
            scanf("%[^\n]",input[j]);
            
        }
        
        
        
        if(flag()){
            printf("Run #%d: Accepted %d\n",times,add);
        }
        else if(judge()){
            printf("Run #%d: Presentation Error %d\n",times,add);
        }
        else{
            printf("Run #%d: Wrong Answer %d\n",times,add);
        }
        times++;
    }
}
