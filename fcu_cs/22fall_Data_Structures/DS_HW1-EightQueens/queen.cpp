#include <iostream>

using namespace std;

struct pos{
    int r;
    int c;
};

int R;
int C;
int maxQueens = 0;

char ansQueens[10][10];

int pre_placed_amount;
pos pre_placed[100];



void printQueen(char queens[10][10]){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << queens[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_ansQueens(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cout << ansQueens[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


bool checkQueen(char queens[10][10], int row, int col){
    for(int i=0; i<row; i++) {
        if(queens[i][col]=='Q')
            return false;
    }

    for(int i=row-1, j=col+1; i>=0 && j<C; i--, j++) {
        if(queens[i][j]=='Q')
            return false;
    }

    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
        if(queens[i][j]=='Q')
            return false;
    }


    return true;
}

bool isPrepPlaced(int r, int c){
    for(int i = 0; i < pre_placed_amount; i++){
        if(pre_placed[i].r == r && pre_placed[i].c == c){
            return true;
        }
    }

    cout << "R" << r << "C" << c << endl;

    return false;
}

void placeQueen(char queens[10][10], int row, int cnt) {
    // cout << "cnt: " << cnt << "maxQueens:" << maxQueens << endl;
    if(cnt>maxQueens) {
        // printQueen(queens);
        maxQueens = cnt;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                ansQueens[i][j] = queens[i][j];
            }
        }
        return;
    }
    for(int j=0; j<C; j++) {
        if(checkQueen(queens, row, j) && !isPrepPlaced(row, j)) {
            queens[row][j]='Q';
            placeQueen(queens, row+1, cnt+1);
            queens[row][j]='.';
        }
    }
}

int main() {
    char queens[10][10];

    while(cin >> C >> R >> pre_placed_amount){
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                queens[i][j] = '.';
            }
        }

        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                ansQueens[i][j] = '.';
            }
        }

        maxQueens = 0;
        for(int i=0; i<pre_placed_amount; i++) {
            cin >> pre_placed[i].c >> pre_placed[i].r;
            queens[pre_placed[i].r][pre_placed[i].c] = 'Q';
            ansQueens[pre_placed[i].r][pre_placed[i].c] = 'Q';
        }

        printQueen(queens);

        // print_ansQueens();
        

        placeQueen(queens, 0, 0);
        // cout << "_____" << endl;
        print_ansQueens();
        cout << maxQueens << endl;
    }

    

    return 0;
}

// 5 3 2
// 3 2
// 4 2