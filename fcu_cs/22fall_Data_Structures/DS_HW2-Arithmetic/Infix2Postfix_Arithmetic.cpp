#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack <char> ValidParentheses;

bool isDigit(char c){
    if(c >= '0' && c <= '9')
        return true;
    else
        return false;
}

int ISP(char c){
    switch(c){
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
        case '[':
        case '{':
            return 0;
    }

    return -1;
}

int ICP(char c){
    switch(c){
        case '(':
            return 6;
        case '[':
            return 5;
        case '{':
            return 4;
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
    }

    return -1;
}


bool checkBrackets(){
    if(ValidParentheses.size() > 1){
        char up = ValidParentheses.top(); ValidParentheses.pop();
        char dn = ValidParentheses.top(); ValidParentheses.pop();
        if((up - '0') > (dn - '0')){
            return false;
        }
        else{
            ValidParentheses.push(dn);
            ValidParentheses.push(up);
        }
    }

    return true;
}



int main(){
    string str;

    while(cin >> str){
        stack <char> s;

        string ans = "";
        
        int val = 0;
        bool isValid = true;

        cout << str << endl;
        for(int i=0; i<str.length(); i++){
            cout << str[i] << endl;
            if(!checkBrackets()){
                isValid = false;
                break;
            }

            if(isDigit(str[i])){
                val += (str[i] - '0');

                int index = i+1;
                while(index != str.length() && isDigit(str[index])){
                    val = val * 10 + (str[index] - '0');
                    index++;
                }

                ans += to_string(val);
                val = 0;
                i = index - 1;
            }
            else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
                if(ValidParentheses.empty()){
                    isValid = false;
                    break;
                }
                else{
                    char top = ValidParentheses.top(); ValidParentheses.pop();
                    if((top == '(' && str[i] != ')') || (top == '[' && str[i] != ']') || (top == '{' && str[i] != '}')){
                        isValid = false;
                        break;
                    }
                    else{
                        while(s.top() != '(' && s.top() != '[' && s.top() != '{'){
                            ans += s.top();
                            s.pop();
                        }
                        s.pop();
                    }
                }
            }
            else if(s.empty() || (ICP(str[i]) > ISP(s.top()))){
                s.push(str[i]);

                if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                    ValidParentheses.push(str[i]);
                }
            }
            else{
                while(!s.empty() && (ICP(str[i]) <= ISP(s.top()))){
                    ans += s.top();
                    s.pop();
                }
                s.push(str[i]);

                if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                    ValidParentheses.push(str[i]);
                }
            }
        }

        while(!s.empty()){
            ans += s.top();
            s.pop();
        }

        if(isValid)
            cout << ans << endl;
        else
            cout << "ERROR" << endl;

        while(!ValidParentheses.empty()){
            ValidParentheses.pop();
        }
    }
}