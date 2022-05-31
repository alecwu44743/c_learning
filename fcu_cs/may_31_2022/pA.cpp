// UVA 12218 - An Industrial Spy
// http://poj.org/problem?id=3842

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int primeTable[10000000] = {0};
void primeTableInit(){
    primeTable[0] = 1;
    primeTable[1] = 1;
    for (int i=2; i < 10000000; i++){
        if (primeTable[i] == 0){
            for (int j=i+i; j < 10000000; j+=i){
                primeTable[j] = 1;
            }
        }
    }
}

int cptcp(string input){ // Combination and Permutation Then Count the Prime
    set <int> data;

    for(int i=1; i<(1 << input.size()); i++){
        string num = "";

        for(int j=0; j<input.size(); j++){
            if(i & (1 << j)){
                num += input[j];
            }
        }

        do{
            if(primeTable[stoi(num)] == 0){
                // cout << stoi(num) << endl;
                data.insert(stoi(num));
            }
        }while(next_permutation(num.begin(), num.end()));
    }

    return data.size();
}


int main(){
    cin.sync_with_stdio(false), cin.tie(nullptr);

    primeTableInit();

    int n;
    string str;
    while(cin >> n){
        while(n--){
            cin >> str;
            sort(str.begin(), str.end());

            cout << cptcp(str) << endl;
        }
    }
}

// Reference : https://aisumura.net/blog/2021/09/06/uva12218-an-industrial-spy/
