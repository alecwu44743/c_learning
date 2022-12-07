#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

int tree[100];
int num = 0;


int root = 0;

void insert_tree_array(int val){
    int pos = root;
    while(1){
        if(tree[pos] == 0){
            tree[pos] = val;
            break;
        }
        else if(val < tree[pos]){
            pos = pos*2+1;
        }
        else{
            pos = pos*2+2;
        }
    }
}

int find(int val){
    int pos = root;
    while(tree[pos] != 0){
        if(val == tree[pos]){
            return pos;
        }else if(val < tree[pos]){
            pos = pos*2+1;
        }else{
            pos = pos*2+2;
        }
    }
    return -1;
}

int findMin(int p){
    while(tree[p*2+1] != 0){
        p = p*2+1;
    }
    return p;
}

int findMax(int p){
    while(tree[p*2+2] != 0){
        p = p*2+2;
    }
    return p;
}

void delete_tree_array(int val){
    int index = find(val);
    int sub;

    if(index == -1){
        return;
    }
    
    if(tree[index*2+1] != 0){ // left child exists
        int sub = findMax(index*2+1);
        delete_tree_array(tree[sub]);
        tree[index] = tree[sub];
    }
    else if(tree[index*2+2] != 0){ // right child exists
        int sub = findMin(index*2+2);
        delete_tree_array(tree[sub]);
        tree[index] = tree[sub];
    }
    else{ // no child
        tree[index] = 0;
    }
}



void print_tree_array(){
    for(int i=0; i<100; i++){
        if(num == 0) break;

        if(tree[i] > 0){
            cout << tree[i] << " ";
            num--;
        }
        else{
            cout << 0 << " ";
        }
    }
    cout << endl;
}




int main(){
    int input;

    memset(tree, 0, sizeof(tree));

    // insert
    while(cin >> input && input != -1){
        insert_tree_array(input);
        num++;
    }

    // // delete
    // while(cin >> input && input != -1){
    //     delete_tree_array(input);
    //     num--;
    // }

    // print
    print_tree_array();
}