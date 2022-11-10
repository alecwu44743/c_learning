#include <iostream>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

stack <char> ValidParentheses;

bool isDigit(char c){
    if(c >= '0' && c <= '9')
        return true;
    else
        return false;
}

bool isOperator(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return true;
    else
        return false;
}

bool isParentheses(char c){
    if(c == '(' || c == '[' || c == '{' || c == ')' || c == ']' || c == '}')
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


void postfix_operator(string str){
    stack <int> nums;

    for(int i=0; i<str.length(); i++){
        if(isDigit(str[i])){
            int val = 0;
            while(isDigit(str[i])){
                val = val * 10 + (str[i] - '0');
                i++;
            }

            nums.push(val);
        }
        else if(str[i] != ' '){
            int b = nums.top(); nums.pop();
            int a = nums.top(); nums.pop();

            switch(str[i]){
                case '+':
                    nums.push(a + b);
                    break;
                case '-':
                    nums.push(a - b);
                    break;
                case '*':
                    nums.push(a * b);
                    break;
                case '/':
                    nums.push(a / b);
                    break;
                case '^':
                    nums.push(pow(a, b));
                    break;
            }
        }
    }

    cout << "Postfix: " << str << endl;
    cout << "Ans: " << nums.top() << endl;
}



int main(){
    string str;

    while(getline(cin, str)){
        stack <char> s;

        string ans = "";
        string clear_str = "";
        
        int val = 0;
        bool isValid = true;

        int num_cnt = 0;
        int op_cnt = 0;

        for(int i=0; i<str.length(); i++){
            if(!isDigit(str[i]) && !isOperator(str[i]) && !isParentheses(str[i])){
                continue;
            }

            clear_str += str[i];
            clear_str += ' ';
            
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

                if(index != str.length()){
                    if(str[index] == '(' || str[index] == '[' || str[index] == '{'){
                        isValid = false;
                        break;
                    }
                }

                num_cnt++;
                ans += to_string(val);
                ans += ' ';
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
                            ans += ' ';
                            op_cnt++;
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
                    ans += ' ';
                    op_cnt++;
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
            ans += ' ';
            op_cnt++;
            s.pop();
        }

        if(isValid && checkBrackets() && ValidParentheses.empty() && num_cnt == op_cnt + 1){
            cout << "Infix: " << clear_str << endl;
            postfix_operator(ans);
            // cout << ans << endl;
        }
        else
            cout << "ERROR" << endl;

        while(!ValidParentheses.empty()){
            ValidParentheses.pop();
        }


        cout << endl;
    }
}


// 測資1: (10+3)*5-6 輸出:59 
// 測資2: 2^[4*(5-(2+3))] 輸出:1 
// 測資3: 3+(2*[1+4]) 輸出:ERROR 
// 測資4: 2(1+3) 輸出:ERROR

// 2 3 4 - * 12 4 / +
// 2*(3-4)+12/4
// 2*(3- 4 ) + 12/4


// ((2*(3-4))+(12/4))
// ( ( 2 * ( 3 - 4 ) ) + ( 12 / 4 ) )
// ( ( 2 * ( 3 -         4 ) ) + ( 12 / 4 jiojeoiwjexo) )