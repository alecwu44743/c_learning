#include <iostream>
#include <stack>

using namespace std;


int main(){
    int n;
    

    while(cin >> n){
        if(n == 0) break;

        while(1){
            stack <int> train;
            train.push(1);

            int cnt = 2;
            int t;
            bool isValid = true;
            bool toBreak = false;

            for(int i=0; i<n; i++){
                cin >> t;

                if(t == 0){
                    toBreak = true;
                    break;
                }

                while(cnt <= n && (train.empty() || train.top() != t)){
                    train.push(cnt++);
                }

                if(train.empty() || train.top() != t){
                    isValid = false;
                }
                else{
                    train.pop();
                }
            }

            if(toBreak) break;

            if(isValid){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }

        cout << endl;
    }
}