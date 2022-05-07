// 10142 - Australian Voting
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1083



#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

int main(){
    cin.sync_with_stdio(false), cin.tie(nullptr);

    int t, n;
    int remains, voteN, votes[1000][20], count[20];
    int index, half, _min, _max;

    string candidate[20], buffer[20], input;
    bool kickedoff[20];

    cin >> t >> ws;
    while(t--){
        cin >> n >> ws;

        for(int i=0; i<n; ++i){
            getline(cin, candidate[i]);
        }
        voteN = 0;
        memset(kickedoff, 0, sizeof(kickedoff));

        while(getline(cin, input) && input.size()){
            stringstream ss(input);

            for(int i=0; i<n; ++i){
                ss >> votes[voteN][i];
            }
            ++voteN;
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
                        buffer[0] = candidate[i], index = 1;
                        _max = count[i];
                    }
                    else if(count[i] == _max){
                        buffer[index] = candidate[i], ++index;
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
                    kickedoff[i] = true, --remains;
                }
            }
        }

        if(index == remains){
            for(int i=0; i<index; ++i){
                cout << buffer[i] << '\n';
            }
        }
        else{
            cout << buffer[0] << '\n';
        }

        if(t) cout << '\n';
    }

}