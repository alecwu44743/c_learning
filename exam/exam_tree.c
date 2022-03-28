#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node *root = NULL;

void inOrder(Node *start){
    if(start != NULL){
        inOrder(start->left);
        printf("%d ", start->data);
        inOrder(start->right);
    }
}

void preOrder(Node *start){
    if(start != NULL){
        printf("%d ", start->data);
        preOrder(start->left);
        preOrder(start->right);
    }
}

void postOrder(Node *start){
    if(start != NULL){
        postOrder(start->left);
        postOrder(start->right);
        printf("%d ", start->data);
    }
}

void tree_insert(int val){
    Node *newNode, *prev, *curr;
    newNode = (Node *)malloc(sizeof(Node));

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    prev = NULL;
    curr = root;

    if(curr == NULL){
        root = newNode;
    }
    else{
        while(1){
            prev = curr;

            if(val < prev->data){
                curr = curr->left;

                if(curr == NULL){
                    prev->left = newNode;
                    return;
                }
            }
            else if(val > curr->data){
                curr = curr->right;

                if(curr == NULL){
                    prev->right = newNode;
                    return;
                }
            }
            else{
                printf("dup.\n");
                return;
            }
        }
    }
}

void search(int val){
    Node *curr = root;
    
    while(curr->data != val){
        if(curr != NULL) printf("%d ", curr->data);

        if(val < curr->data){
            curr = curr->left;
        }
        else if(val > curr->data){
            curr = curr->right;
        }

        if(curr == NULL){
            printf("Sorry bro. %d not found.\n", val);
            return;
        }
    }

    printf("[%d] Element found.\n", val);
}

void delete(int val){
    Node *prev = NULL;
    Node *curr = root;

    while(curr != NULL && curr->data != val){
        prev = curr;

        if(val < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }

    if(curr == NULL){
        printf("Not found %d\n", val);
        return;
    }

    if(curr->left == NULL || curr->right == NULL){
        Node *newCurr;

        if(curr->left == NULL){
            newCurr = curr->right;
        }
        else{
            newCurr = curr->left;
        }

        if(prev == NULL){
            root = newCurr;
            return;
        }

        if(prev->left == curr){
            prev->left = newCurr;
        }
        else{
            prev->right = newCurr;
        }

        free(curr);
    }
    else{
        Node *pprev = NULL;
        Node *temp = curr->right;

        while(temp->left != NULL){
            pprev = temp;
            temp = temp->left;
        }

        if(pprev == NULL){
            curr->right = temp->right;
        }
        else{
            pprev->left = temp->right;
        }

        curr->data = temp->data;
        free(temp);
    }
}

int main(){
    int data[10] = {9, 1, 2, 3, 7, 5, 6, 4, 8, 0};

    for(int i = 0; i < 10; i++){
        tree_insert(data[i]);
    }

    inOrder(root);
    printf("\n");

    preOrder(root);
    printf("\n");

    postOrder(root);
    printf("\n");

    search(9);
    search(1);
    search(15);

    delete(9);
    delete(1);
    delete(15);

    inOrder(root);
    printf("\n");
}