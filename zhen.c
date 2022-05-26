#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

int a = 0;
node *root = NULL;

node *insert(node *Node, int value){
    if(Node != NULL){
        if(value > Node->data){
            Node->right = insert(Node->right, value);
        }
        else if(value < Node->data){
            Node->left = insert(Node->left, value);
        }
    }
    else {
        Node = malloc(sizeof(node));
        Node->data = value;
        Node->left = NULL;
        Node->right = NULL;
    }
    return Node;
}

node *Delete(node *root, int value){
    if(root == NULL)    return root;
    if(value > root->data){
        root->right = Delete(root->right, value);
    }
    else if(value < root->data){
        root->left = Delete(root->left, value);
    }
    else {
        if(root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }
        else{
            node *temp = root->right;
            while(temp && temp->left){
             temp = temp->left;
            }
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
   return root;
}
void searching(int n){
    node *cur = root;

    while(cur != NULL && cur->data != n){
        if(cur->data < n)  cur = cur->right;
        else    cur = cur->left;
    }

    if(cur == NULL) printf("No\n");
    else    printf("Yes\n");
}

void print(node *origin){
    if(origin != NULL){
        print(origin->left);
        if(a == 0){
            printf("%d", origin->data);
            a = 1;
        }
        else{
            printf(" %d", origin->data);
        }
        print(origin->right);
    }
}

int main(){
    int x, n;

    while(scanf("%d", &x) != EOF && x > 0){
        if(x == 1 || x == 2){
            scanf("%d", &n);
            root = insert(root, n);
        }
        else if(x == 3){
            scanf("%d", &n);
            root = Delete(root, n);
        }
        else if(x == 4){
            scanf("%d", &n);
            searching(n);
        }
        else{
            print(root);
            printf("\n");
            a = 0;
        }
    }
}