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

int ISP(char c){ // ISP -> In Stack Priority
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

int ICP(char c){ // ICP -> Incoming Priority
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
    if(ValidParentheses.size() > 1){ // check if there are more than one brackets
        char up = ValidParentheses.top(); ValidParentheses.pop();
        char dn = ValidParentheses.top(); ValidParentheses.pop();
        if((up - '0') > (dn - '0')){ // check if the up bracket is bigger than the down bracket
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
    stack <int> nums; // store the numbers

    for(int i=0; i<str.length(); i++){
        if(isDigit(str[i])){ // if the character is a number
            int val = 0;
            while(isDigit(str[i])){
                val = val * 10 + (str[i] - '0');
                i++;
            }

            nums.push(val);
        }
        else if(str[i] != ' '){ // if the character is an operator
            int b = nums.top(); nums.pop(); // pop the top two numbers
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


void output_oj(string str){ // output the answer for the online judge
    stack <double> nums;

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
            double b = nums.top(); nums.pop();
            double a = nums.top(); nums.pop();

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

    // cout << "Postfix: " << str << endl;
    printf("%.2f\n", nums.top());
}



int main(){
    string str;

    while(getline(cin, str)){
        stack <char> s;

        string ans = ""; // postfix
        string clear_str = ""; // infix
        
        int val = 0;
        bool isValid = true;

        int num_cnt = 0; // numbers of digits
        int op_cnt = 0; // numbers of operators

        for(int i=0; i<str.length(); i++){
            if(!isDigit(str[i]) && !isOperator(str[i]) && !isParentheses(str[i])){ // if str[i] is not a digit, operator, or parentheses
                isValid = false;
                break;
            }

            clear_str += str[i];
            clear_str += ' ';
            
            if(!checkBrackets()){ // check brackets are valid
                isValid = false;
                break;
            }

            if(isDigit(str[i])){ // if str[i] is a digit
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
            else if(str[i] == ')' || str[i] == ']' || str[i] == '}'){ // if str[i] is a right parentheses
                if(ValidParentheses.empty()){
                    isValid = false;
                    break;
                }
                else{
                    char top = ValidParentheses.top(); ValidParentheses.pop();
                    if((top == '(' && str[i] != ')') || (top == '[' && str[i] != ']') || (top == '{' && str[i] != '}')){ // check parentheses are valid
                        isValid = false;
                        break;
                    }
                    else{
                        while(s.top() != '(' && s.top() != '[' && s.top() != '{'){ // pop all operators in stack
                            ans += s.top();
                            ans += ' ';
                            op_cnt++;
                            s.pop();
                        }
                        s.pop(); // pop left parentheses
                    }
                }
            }
            else if(s.empty() || (ICP(str[i]) > ISP(s.top()))){ // if str[i] is a left parentheses or operator with higher precedence
                s.push(str[i]);

                if(str[i] == '(' || str[i] == '[' || str[i] == '{'){ // if str[i] is a left parentheses
                    ValidParentheses.push(str[i]);
                }
            }
            else{
                while(!s.empty() && (ICP(str[i]) <= ISP(s.top()))){ // if str[i] is a operator with lower precedence
                    ans += s.top();
                    ans += ' ';
                    op_cnt++;
                    s.pop();
                }
                s.push(str[i]); // push str[i] to stack

                if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                    ValidParentheses.push(str[i]);
                }
            }
        }

        while(!s.empty()){ // pop all operators in stack
            ans += s.top();
            ans += ' ';
            op_cnt++;
            s.pop();
        }

        if(isValid && checkBrackets() && ValidParentheses.empty() && num_cnt == op_cnt + 1){ // check infix is valid
            // cout << "Infix: " << clear_str << endl;
            // postfix_operator(ans); // calculate postfix
            output_oj(ans);
            // cout << ans << endl;
        }
        else
            cout << "ERROR" << endl;

        while(!ValidParentheses.empty()){ // clear ValidParentheses
            ValidParentheses.pop();
        }


        // cout << endl;
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