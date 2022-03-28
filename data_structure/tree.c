#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    // int height;
}Node;

Node *root = NULL;

void tree_insert(int val){
    Node* newNode;
    Node *prev, *curr;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    // newNode->height = 1;

    if(root == NULL){ // empty tree
        root = newNode;
    }
    else{ // non-empty tree
        prev = NULL;
        curr = root;

        while(1){
            prev = curr;
            // newNode->height++; // height of new node

            if(val < curr->data){
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
                printf("%d is duplicate node.\n", val);
                return;
            }
        }
    }
}

void tree_search(int val){
    Node *curr = root;

    printf("Searching Traversal: ");

    while(curr->data != val){
        if(curr != NULL) printf("%d ", curr->data);

        if(val < curr->data){
            curr = curr->left;
        }
        else if(val > curr->data){
            curr = curr->right;
        }

        if(curr == NULL){
            printf("(Oops, %d not found)\n", val);
            return;
        }
    }

    printf("[%d] Element found.\n", val);
}

void tree_delete(int val){
    Node *curr = root;
    Node *prev = NULL;

    while(curr != NULL && curr->data != val){
        prev = curr;
        if(curr->data > val){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }

    }

    if(curr == NULL){
        printf("Not found.\n");
        return;
    }

    if(curr->left == NULL || curr->right == NULL){ // leaf node
        Node *newCurr;

        if(curr->left == NULL){
            newCurr = curr->right;
        }
        else{
            newCurr = curr->left;
        }
        // newCurr = (curr->left == NULL) ? curr->right : curr->left;

        if(prev == NULL){
            root = newCurr;
            return;
        }

        if(curr == prev->left){
            prev->left = newCurr;
        }
        else{
            prev->right = newCurr;
        }

        free(curr);
    }
    else{ // non-leaf node
        Node *p = NULL;
        Node *temp;

        temp = curr->right;
        while(temp->left != NULL){ // find the smallest node in the right subtree
            p = temp;
            temp = temp->left;
        }

        if(p != NULL){ // if the smallest node is not the right child of curr
            p->left = temp->right; // connect the right subtree of the smallest node to the left subtree of curr
        }
        else{ // if the smallest node is the right child of curr
            curr->right = temp->right; // connect the right subtree of the smallest node to the right subtree of curr
        }

        curr->data = temp->data; // copy the smallest node to curr
        free(temp);
    }
}

void tree_inOrder(Node *start){
    if(start != NULL){
        tree_inOrder(start->left);
        printf("%d ", start->data);
        tree_inOrder(start->right);
    }
}

void tree_preOrder(Node *start){
    if(start != NULL){
        printf("%d ", start->data);
        tree_preOrder(start->left);
        tree_preOrder(start->right);
    }
}

void tree_postOrder(Node *start){
    if(start != NULL){
        tree_postOrder(start->left);
        tree_postOrder(start->right);
        printf("%d ", start->data);
    }
}

int main(){
    int data[8] = { 27, 14, 35, 10, 19, 19, 31, 42 }; // 27,14,35,10,19,31,42,100
    for(int i=0; i<8; i++){
        tree_insert(data[i]);
    }

    // tree_insert(27);

    printf("Preorder Traversal: "), tree_preOrder(root), printf("\n");
    printf("Inorder Traversal: "), tree_inOrder(root), printf("\n");
    printf("Postorder Traversal: "), tree_postOrder(root), printf("\n");

    // tree_delete(27);
    // tree_inOrder(root);
    // printf("aaaa\n");

    tree_search(30);
    tree_search(27);
    tree_search(42);
    tree_search(19);

    tree_insert(100);
    tree_insert(200);
    tree_inOrder(root);
    printf("\n");

    tree_delete(19);
    tree_delete(14);
    tree_delete(35);
    tree_delete(100);
    tree_delete(200000);

    tree_inOrder(root);
    printf("\n");
}