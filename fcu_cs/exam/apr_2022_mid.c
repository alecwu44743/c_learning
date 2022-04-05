#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

// a743: 10420 - List of Conquests - https://zerojudge.tw/ShowProblem?problemid=a743
void ListofConquests(){
    int n;
    char country[2001][76] = {0};
    char name[76] = {0};
    char temp[76] = {0};

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s", country[i]);
        gets(name);

        if(strlen(name) > 75) i--;
    }

    // sort country
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(strcmp(country[j], country[j+1]) > 0){
                strcpy(temp, country[j]);
                strcpy(country[j], country[j+1]);
                strcpy(country[j+1], temp);
            }
        }
    }

    int flag = false;
    int cnt = 0;
    int i = 0;

    while(i < n){
        if(!flag){
            printf("%s ", country[i]);
            cnt++;
            flag = true;
        }
        else if(flag){
            if(strcmp(country[i], country[i+1]) == 0){
                cnt++;
            }
            else{
                printf("%d\n", cnt);
                flag = false;
                cnt = 0;
            }
            i++;
        }
    }
}



// c004: 10812 - Beat the Spread! - https://zerojudge.tw/ShowProblem?problemid=c004
// (1) s = s + y
// (2) d = x - y
// 
// (1) + (2)
//  => s + d = 2x, must be even
//  => s – d = 2y, must be greater than zero
void beat(){
    int t, s, d;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &s, &d);
        if((s+d) % 2 || s < d){
            printf("impossible\n");
        }
        else{
            printf("%d %d\n", (s+d)/2, (s-d)/2);
        }
    }
}








int main(){
    // ListofConquests();
}