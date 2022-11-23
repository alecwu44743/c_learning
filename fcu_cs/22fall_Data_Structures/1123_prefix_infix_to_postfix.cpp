#include <iostream>
#include <string>
using namespace std;


struct tree_node{
    char val;
    tree_node *left;
    tree_node *right;
};


tree_node *root = NULL;


tree_node* create(string prefix, string infix){
    if(prefix.size() == 0){
        return NULL;
    }

    tree_node *r = new tree_node;
    r->val = prefix[0];
    r->left = NULL;
    r->right = NULL;


    int pos = infix.find(prefix[0]);
    string left_infix = infix.substr(0, pos);
    string right_infix = infix.substr(pos+1);

    string left_prefix = prefix.substr(1, left_infix.size());
    string right_prefix = prefix.substr(1+left_infix.size());

    r->left = create(left_prefix, left_infix);
    r->right = create(right_prefix, right_infix);

    return r;
}



void traversal_postorder(tree_node *r){
    if(r == NULL){
        return;
    }

    traversal_postorder(r->left);
    traversal_postorder(r->right);
    cout << r->val;
}


int main(){
    string prefix;
    string infix;

    cin >> prefix;
    cin >> infix;

    root = create(prefix, infix);

    traversal_postorder(root);
    cout << endl;
}