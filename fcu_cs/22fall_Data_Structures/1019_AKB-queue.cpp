#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

struct man{
    char _akb;
    int time;
    string name;
};


int main(){
    queue <man> a;
    queue <man> k;
    queue <man> b;

    man temp;
    int total_time, num;
    while(cin >> total_time >> num){
        while(total_time > 0 || num > 0){
            if(num > 0){
                cin >> temp._akb >> temp.time >> temp.name;
                if(temp._akb == 'A'){
                    a.push(temp);
                }
                else if(temp._akb == 'K'){
                    k.push(temp);
                }
                else if(temp._akb == 'B'){
                    b.push(temp);
                }
                num--;

                if(total_time <= 0){
                    break;
                }
            }

            if(!a.empty()){
                a.front().time--;

                if(a.front().time == 0){
                    a.pop();
                }
            }

            if(!k.empty()){
                k.front().time--;

                if(k.front().time == 0){
                    k.pop();
                }
            }

            if(!b.empty()){
                b.front().time--;

                if(b.front().time == 0){
                    b.pop();
                }
            }
            total_time--;
        }

        string stemp = "";

        cout << "A:";
        if(a.empty()){
            cout << " ";
        }
        else{
            while(!a.empty()){
                if(stemp == a.front().name){
                    a.pop();
                    continue;
                }
                cout << " " << a.front().name;
                stemp = a.front().name;
                a.pop();
            }
        }
        cout << "." << endl;

        cout << "K:";
        if(k.empty()){
            cout << " ";
        }
        else{
            while(!k.empty()){
                if(stemp == k.front().name){
                    k.pop();
                    continue;
                }
                cout << " " << k.front().name;
                stemp = k.front().name;
                k.pop();
            }
        }
        cout << "." << endl;

        cout << "B:";
        if(b.empty()){
            cout << " ";
        }
        else{
            while(!b.empty()){
                if(stemp == b.front().name){
                    b.pop();
                    continue;
                }
                cout << " " << b.front().name;
                stemp = b.front().name;
                b.pop();
            }
        }
        cout << "." << endl;
    }
}