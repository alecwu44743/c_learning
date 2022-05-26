// sample output is wrong.
// Please follow R < root < L !!

#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

int p = 0;
node *root = NULL;

// #1 #2 - insert node at the beginning
void tree_insert(int op, int val){
    node *newNode;
    node *prev, *curr;

    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    if(op == 1){ // empty tree
        root = newNode;
    }
    else{ // op == 2, non-empty tree
        prev = NULL;
        curr = root;

        while(1){
            prev = curr;

            if(val > curr->data){
                curr = curr->right;

                if(curr == NULL){
                    prev->right = newNode;
                    return;
                }
            }
            else if(val < curr->data){
                curr = curr->left;

                if(curr == NULL){
                    prev->left = newNode;
                    return;
                }
            }   
            else{
                return;
            }
        }
    }
}


void tree_search(int val){
    node *curr = root;
    node *prev = NULL;

    while(curr != NULL && curr->data != val){
        prev = curr;

        if(curr->data < val){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }

    if(curr == NULL){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
}


void tree_delete(int val){
    node *curr = root;
    node *prev = NULL;

    while(curr != NULL && curr->data != val){
        prev = curr;

        if(curr->data < val){
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }

    if(curr == NULL) return;

    if(curr->left == NULL || curr->right == NULL){
        node *newCurr;

        if(curr->left == NULL){
            newCurr = curr->right;
        }
        else{
            newCurr = curr->left;
        }

        if(prev == NULL){
            root = newCurr;
        }
        else{
            if(prev->left == curr){
                prev->left = newCurr;
            }
            else{
                prev->right = newCurr;
            }
        }

        free(curr);
    }
    else{
        node *p = NULL;
        node *temp;

        temp = curr->right;
        while(temp->left != NULL){
            p = temp;
            temp = temp->left;
        }

        if(p != NULL){
            p->left = temp->right;
        }
        else{
            curr->right = temp->right;
        }

        curr->data = temp->data;
        free(temp);
    }
}


void print_inOrder(node *start){
    if(start != NULL){
        print_inOrder(start->left);
        if(p == 0){
            printf("%d", start->data);
            p = 1;
        }
        else{
            printf(" %d", start->data);
        }
        print_inOrder(start->right);
    }
}

int main(){
    int op;
    int n;

    while(scanf("%d", &op) != EOF && op > 0){
        if(op == 1 || op == 2){
            scanf("%d", &n);
            tree_insert(op, n);
        }
        else if(op == 3){
            scanf("%d", &n);
            tree_delete(n);
        }
        else if(op == 4){
            scanf("%d", &n);
            tree_search(n);
        }
        else{
            print_inOrder(root);
            printf("\n");
            p = 0;
        }
    }
}