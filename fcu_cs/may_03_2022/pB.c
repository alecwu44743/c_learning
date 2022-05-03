// 10142 - Australian Voting
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1083

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

char candidate[21][100];

char buff[1001];
int choice[1001][21];

int vote[21][1001];
int vote_size[21];

int main(){
    int ccase;
    int n;

    while(scanf("%d", &ccase) != EOF){
        while(ccase--){
            scanf("%d", &n);
            getchar();

            for(int i=0; i<n; i++){
                gets(candidate[i]);
                vote_size[i] = 0;
            }

            int number = 0;
            while(gets(buff) && buff[0]){
                int val = 0;
                int index = 0;

                for(int i=0; i<strlen(buff); i++){
                    if('1' <= buff[i] && buff[i] <= '9'){
                        val *= 10;
                        val += buff[i] - '0';
                    }
                    else{
                        choice[number][index++] = val-1;
                        val = 0;
                    }
                }
                choice[number++][index++] = val - 1;
            }

            for(int i=0; i<number; i++){
                int candt = choice[i][0];
                vote[candt][vote_size[candt]++] = i;
            }

            while(1){
                int _max = 0;
                int _min = 1001;
                int max_i, min_i;

                for(int i=0; i<n; i++){
                    if(_max < vote_size[i]){
                        _max = vote_size[i];
                        max_i = i;
                    }
                    if(_min > vote_size[i]){
                        _min = vote_size[i];
                        min_i = i;
                    }
                }

                if(_max*2 >= number) break;
                if(_max == _min) break;

                for(int k = 0; k<n; k++){
                    if(vote_size[k] != _min) continue;

                    for(int i=0; i<vote_size[k]; i++){
                        int per = vote[k][i];

                        for(int j=0; j<n; j++){
                            int cand = choice[per][j];
                            if(vote_size[cand] != _min && vote_size[cand]){
                                vote[cand][vote_size[cand]++] = per;
                                break;
                            }
                        }
                    }
                    vote_size[k] = 0;
                }
            }

            int max_i = 0;
            for(int i=0; i<n; i++){
                if(vote_size[max_i] < vote_size[i]){
                    max_i = i;
                }
            }
            for(int i=0; i<n; i++){
                if(vote_size[max_i] == vote_size[i]){
                    puts(candidate[i]);
                }
            }

            if(ccase) puts("");
        }
    }
}