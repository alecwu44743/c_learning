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

int ansQp_index = 0;
pos ansQueensPos[100];


void printQueen(char queens[10][10]){ // The function that will be used in the test, print the result in queens
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

void print_ansQueensPos(){ // print ths position
    cout << "R C" << endl;

    for(int i = 0; i < ansQp_index; i++){
        cout << ansQueensPos[i].r << " " << ansQueensPos[i].c << endl;
    }
    cout << endl;
}

void print_ansQueensPos_checker(){ // print ths position
    // cout << "R C" << endl;

    cout << ansQp_index << endl;
    for(int i = 0; i < ansQp_index; i++){
        cout << ansQueensPos[i].c << " " << ansQueensPos[i].r << endl;
    }
    cout << endl;
}


bool checkQueen(char queens[10][10], int row, int col){ // Check if this location can be placed
    for(int i=0; i<R; i++) { // check this col
        if(queens[i][col]=='Q' && i != row)
            return false;
    }

    for(int i=0; i<C; i++){ // check this row
        if(queens[row][i]=='Q' && i != col)
            return false;
    }

    for(int i=row-1, j=col+1; i>=0 && j<C; i--, j++) { // Upper right
        if(queens[i][j]=='Q')
            return false;
    }

    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) { // Upper left
        if(queens[i][j]=='Q')
            return false;
    }

    for(int i=row+1, j=col+1; i<R && j<C; i++, j++) { // Lower right
        if(queens[i][j]=='Q')
            return false;
    }

    for(int i=row+1, j=col-1; i<R && j>=0; i++, j--) { // Lower left
        if(queens[i][j]=='Q')
            return false;
    }

    return true; // If it passes all the checks, it can be placed
}

bool isPrePlaced(int r, int c){ // Check if this location is pre-placed
    for(int i = 0; i < pre_placed_amount; i++){
        if(pre_placed[i].r == r && pre_placed[i].c == c){
            return true;
        }
    }

    return false;
}

int howManyQueens(char queens[10][10]){ // Count how many queens are placed
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

void placeQueen(char queens[10][10], int row) {
    int QQ = howManyQueens(queens);
    if(QQ > maxQueens){
        // printQueen(queense);
        ansQp_index = 0;
        maxQueens = QQ;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                ansQueens[i][j] = queens[i][j];
                if(!isPrePlaced(i, j) && queens[i][j] == 'Q'){
                    ansQueensPos[ansQp_index].r = i;
                    ansQueensPos[ansQp_index].c = j;
                    ansQp_index++;
                }
            }
        }
    }

    if(row == R) { // If all rows are placed, return
        return;
    }

    bool nexted = false; // whether the next row has been placed
    for(int j=0; j<C; j++) {
        // printQueen(queens);
        if(checkQueen(queens, row, j) && !isPrePlaced(row, j)) {
            // cout << "row" << row << "j" << j << endl;
            queens[row][j]='Q'; // Case 1: Place the queen
            nexted = true; // the next row has been placed
            placeQueen(queens, row+1);
            queens[row][j]='.'; // Case 2: Not place the queen
        }
    }

    if(!nexted){ // if the next row has not been placed, then place the queen in the next row
        placeQueen(queens, row+1);
    }
}

int main() {
    char queens[10][10];

    while(cin >> C >> R >> pre_placed_amount){ // input the data
        for(int i=0; i<R; i++) { // initialize the chessboard
            for(int j=0; j<C; j++) {
                queens[i][j] = '.';
            }
        }

        for(int i=0; i<R; i++) { // intialize the answer chessboard
            for(int j=0; j<C; j++) {
                ansQueens[i][j] = '.';
            }
        }

        maxQueens = 0;
        for(int i=0; i<pre_placed_amount; i++) { // input the pre-placed queens
            cin >> pre_placed[i].c >> pre_placed[i].r;
            queens[pre_placed[i].r][pre_placed[i].c] = 'Q';
            ansQueens[pre_placed[i].r][pre_placed[i].c] = 'Q';
        }
        

        placeQueen(queens, 0); // start to place the queens

        print_ansQueens();
        cout << "Additional Queens amount: " << ansQp_index << endl;
        print_ansQueensPos();

        // print_ansQueensPos_checker();
    }


    return 0;
}
