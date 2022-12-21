#include <iostream>

using namespace std;


int main(){
    int n;
    cin >> n;

    int map[100][100];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }


    // Bellman-Ford
    int dist[100];
    for(int i = 0; i < n; i++){
        dist[i] = 1000000;
    }

    dist[0] = 0;

    for(int i=0; i<n-1; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(map[j][k] != 0){
                    if(dist[j]+map[j][k] < dist[k]){
                        dist[k] = dist[j]+map[j][k];
                    }
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] != 0){
                if(dist[i]+map[i][j] < dist[j]){
                    // cout << "Negative Cycle" << endl;
                    cout << "cycle" << endl;
                    return 0;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}

/*
#1
5
0 7 3 0 0 
7 0 3 9 11
3 3 0 10 0
0 9 10 0 0
0 11 0 0 0
-> 0 6 3 13 17


#2
5
0 11 3 0 0
0 0 0 2 0
0 1 0 5 0
0 0 0 0 6
-4 0 6 0 0
-> 0 4 3 6 12


#3
5
0 11 3 0 0
0 0 0 2 0
0 1 0 5 0
0 0 0 0 6
-14 0 6 0 0
-> Negative Cycle
*/