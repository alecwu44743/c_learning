#include <iostream>
#include <stack>

using namespace std;


int main(){
    int n;
    string str;

    while(cin >> n){
        for(int cnt=0; cnt<n; cnt++){
            cin >> str;

            stack<char> s;
            bool valid = true;
            int status = -1;
            for(int i=0; i<str.length(); i++){ // input: 2*(2+(3-1)) 
                if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                    s.push(str[i]);
                }
                else if(str[i] == ')'){
                    if((s.empty() || s.top() != '(')){
                        valid = false;
                        break;
                    }
                    else{
                        s.pop();
                    }
                }
                else if(str[i] == ']'){
                    if(s.empty() || s.top() != '[' || s.top() == '('){
                        valid = false;
                        break;
                    }
                    else{
                        s.pop();
                    }
                }
                else if(str[i] == '}'){
                    if(s.empty() || s.top() != '{'){
                        valid = false;
                        break;
                    }
                    else{
                        s.pop();
                    }
                }

                if(s.size() > 1){  // Thanks for your hint, Hans
                    char up = s.top(); s.pop();
                    char dn = s.top(); s.pop();
                    if((up - '0') > (dn - '0')){
                        valid = false;
                        break;
                    }
                    else{
                        s.push(dn);
                        s.push(up);
                    }
                }
            }

            if(valid && s.empty()){
                cout << "correct" << endl;
            }
            else{
                cout << "wrong" << endl;
            }
        }
    }
}