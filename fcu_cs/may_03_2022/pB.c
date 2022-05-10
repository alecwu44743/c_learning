// 10142 - Australian Voting
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1083


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int t, n;
    int remains, voteN, votes[1000][20], count[20];
    int index, half, _min, _max;

    char candidate[20][1000], buffer[20][1000], input[1000];
    int kickedoff[20];

    while(scanf("%d", &t) != EOF){
            while(t--){
            scanf("%d", &n);
            getchar();

            for(int i=0; i<n; ++i){
                scanf("%[^\n]", candidate[i]);
                getchar();
            }
            voteN = 0;
            memset(kickedoff, 0, sizeof(kickedoff));

            while(scanf("%[^\n]", input) && input[0] != '\0'){
                getchar();

                int val = 0;
                int index = 0;

                for(int i=0; i<strlen(input); ++i){
                    if(input[i] == ' '){
                        votes[voteN][index] = val;
                        val = 0;
                        index++;
                    }
                    else{
                        val = val*10 + (input[i] - '0');
                    }
                }
                votes[voteN][index] = val;
                voteN++;

                // for(int i=0; i<n; ++i){
                //     ss >> votes[voteN][i];
                // }
                // ++voteN;
            }

            half = voteN >> 1; // -> voteN / 2, it's more efficient
            remains = n;

            while(1){
                memset(count, 0, sizeof(count));
                _max = index = 0;
                _min = 2147483647;

                for(int i=0; i<voteN; ++i){
                    for(int j=0; j<n; ++j){
                        if(!kickedoff[votes[i][j]-1]){
                            ++count[votes[i][j] - 1];
                            break;
                        }
                    }
                }

                for(int i=0; i<n; ++i){
                    if(!kickedoff[i]){
                        if(count[i] > _max){
                            // buffer[0] = candidate[i], index = 1;

                            strcpy(buffer[0], candidate[i]), index = 1;
                            _max = count[i];
                        }
                        else if(count[i] == _max){
                            // buffer[index] = candidate[i], ++index;

                            strcpy(buffer[index], candidate[i]), ++index;
                        }

                        if(count[i] < _min){
                            _min = count[i];
                        }
                    }
                }

                if(index == remains){
                    break;
                }
                if(_max > half){
                    break;
                }

                for(int i=0; i<n; ++i){
                    if(count[i] == _min){
                        kickedoff[i] = 1, --remains;
                    }
                }
            }

            if(index == remains){
                for(int i=0; i<index; ++i){
                    // cout << buffer[i] << '\n';
                    printf("%s\n", buffer[i]);
                }
            }
            else{
                // cout << buffer[0] << '\n';
                printf("%s\n", buffer[0]);
            }

            if(t) printf("\n"); // cout << '\n';
        }

    }
    

}