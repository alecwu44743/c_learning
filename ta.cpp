#include <iostream>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n1, n2;
    while (cin >> n1 >> n2){
        int carry = 0, cnt = 0;
        if (n1 == 0 && n2 == 0) break;
        while (n1 > 0 || n2 > 0){
            int tmp = n1 % 10 + n2 % 10 + carry;
            if (tmp >= 10){
                carry = tmp / 10;
                cnt++;
            } else {
                carry = 0;
            }
            n1 /= 10;
            n2 /= 10;
        }
        if (cnt == 0) cout << "No carry operation.\n";
        else if (cnt == 1) cout << "1 carry operation.\n";
        else cout << cnt << " carry operations.\n";
    }
    return 0;
}