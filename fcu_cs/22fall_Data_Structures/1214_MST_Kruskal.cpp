#include <iostream>
using namespace std;

int graph[101][101];
int parent[101];

int find(int i){
    while(parent[i]){
        i = parent[i];
    }

    return i;
}

int uni(int i, int j){
    if(i != j){
        parent[j] = i;
        return 1;
    }

    return 0;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];

            if(graph[i][j] == 0){
                graph[i][j] = 999;
            }
        }
    }

    int ne = 1;
    int min;
    int minCost = 0;
    int a, b, u, v;
    int i, j;
    while(ne < n){
        for(i=1, min=999; i<=n; i++){
            for(j=1; j<=n; j++){
                if(graph[i][j] < min){
                    min = graph[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);
        if(uni(u, v)){
            cout << "Edge " << ne << ": (" << a-1 << ", " << b-1 << ") cost: " << min << endl;
            minCost += min;
            ne++;
        }

        graph[a][b] = graph[b][a] = 999;
    }

    cout << "Minimum cost: " << minCost << endl;
}