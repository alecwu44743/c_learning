#include <iostream>
#include <queue>

using namespace std;

typedef pair <int, string> baby;

// struct baby{
//     int age;
//     string name;
// };


int main(){
    int n;

    while(cin >> n){
        priority_queue <baby> orph;
        string input;
        int age;

        for(int i=0; i<n; i++){
            cin >> input;

            if(input == "delete"){
                if(!orph.empty()){
                    orph.pop();
                }
            }
            else{
                cin >> age;
                orph.push(baby(age, input));
            }
        }

        while(!orph.empty()){
            cout << orph.top().second << endl;
            orph.pop();
        }
    }
}