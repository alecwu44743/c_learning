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
    for(int i=0; i<R; i++) {
        if(queens[i][col]=='Q' && i != row)
            return false;
    }

    for(int i=0; i<C; i++){
        if(queens[row][i]=='Q' && i != col)
            return false;
    }

    for(int i=row-1, j=col+1; i>=0 && j<C; i--, j++) { // 1
        if(queens[i][j]=='Q')
            return false;
    }

    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) { // 2
        if(queens[i][j]=='Q')
            return false;
    }

    for(int i=row+1, j=col+1; i<R && j<C; i++, j++) { // 4
        if(queens[i][j]=='Q')
            return false;
    }

    for(int i=row+1, j=col-1; i<R && j>=0; i++, j--) { // 3
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

    // cout << "R" << r << "C" << c << endl;

    return false;
}

int howManyQueens(char queens[10][10]){
    int count = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(queens[i][j] == 'Q'){
                count++;
            }
        }
    }
    return count;
}

void placeQueen(char queens[10][10], int row, int cnt) {
    // cout << "  cnt: " << cnt << "maxQueens:" << maxQueens << endl;
    cout << "==="  << "row: " << row << endl;
    printQueen(queens);
    cout << "===" << endl;

    int QQ = howManyQueens(queens);
    if(QQ > maxQueens){
        // printQueen(queense);
        maxQueens = QQ;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                ansQueens[i][j] = queens[i][j];
            }
        }

        // cout << "maxQueens: " << maxQueens << endl;
        // print_ansQueens();

        // print_ansQueens();
        // printQueen(queens);
        // cout << "maxQueens: " << maxQueens << endl;
    }

    if(row == R) {
        return;
    }

    // bool nexted = false;
    for(int j=0; j<C; j++) {
        printQueen(queens);
        if(checkQueen(queens, row, j) && !isPrepPlaced(row, j)) {
            cout << "row" << row << "j" << j << endl;
            queens[row][j]='Q';
            // nexted = true;
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

        // printQueen(queens);

        // print_ansQueens();
        

        for(int i=0; i<R; i++) {
            // printQueen(queens);
            placeQueen(queens, i, 0);
        }
        // cout << "_____" << endl;
        print_ansQueens();
        cout << maxQueens << endl;
        // printQueen(queens);
    }

    

    return 0;
}

/*
5 3 2
3 2
4 2
*/