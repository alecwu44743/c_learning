#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct chr{
    string c;
    int val;

    chr(string c, int val)
        : c(c), val(val)
    {
    }
};


struct Comp{
    bool operator()(chr const& a, chr const& b){
        if(a.val == b.val){
            return a.c > b.c;
        }
        return a.val > b.val;
    }
};


int main(){
    string c;
    int val;
    priority_queue <chr, vector<chr>, Comp > pq;

    while(cin >> c){
        if(c == ".") break;

        cin >> val;
        chr tmp(c, val);
        pq.push(tmp);
    }

    int index = 1;

    while(pq.size() > 1){
        chr tmp1 = pq.top();
        pq.pop();
        chr tmp2 = pq.top();
        pq.pop();

        chr tmp3(tmp1.c + tmp2.c, tmp1.val + tmp2.val);

        cout << index << tmp1.c + tmp2.c;
        index++;

        pq.push(tmp3);
    }
    cout << endl;
}