#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
}Node;

int height(Node *n){
    if(n == NULL){
        return 0;
    }
    else{
        return n->height;
    }
}

int max(int a, int b){
    return a > b ? a : b;
}

Node *createNode(int val){
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node *rightRotation(Node *n){
    printf("Perform right rotation on node:%d\n", n->data);

    Node *leftChild = n->left;
    Node *tempNode = leftChild->right;

    n->left = tempNode;
    leftChild->right = n;

    n->height = max(height(n->left), height(n->right)) + 1;
    leftChild->height = max(height(leftChild->left), height(leftChild->right)) + 1;
    
    return leftChild;
}

Node *leftRotation(Node *n){ 
    printf("Perform left rotation on node:%d\n", n->data);

    Node *rightChild = n->right; 
    Node *tempNode = rightChild->left;

    n->right = tempNode;
    rightChild->left = n;

    n->height = max(height(n->left), height(n->right)) + 1;
    rightChild->height = max(height(rightChild->left), height(rightChild->right)) + 1;

    return rightChild;
}

int balanceFactor(Node *n){
    if(n == NULL){
        return 0;
    }
    else{
        return height(n->left) - height(n->right);
    }
}

Node *insertNode(Node *n, int val){
    if(n == NULL){
        return createNode(val);
    }

    if(val < n->data){
        n->left = insertNode(n->left, val);
    }
    else if(val > n->data){
        n->right = insertNode(n->right, val);
    }
    else{
        printf("%d is duplicate node.\n", val);
        return n;
    }

    n->height = max(height(n->left), height(n->right)) + 1;

    int bf = balanceFactor(n);
    if(bf > 1 && val < n->left->data){
        return rightRotation(n);
    }
    if(bf < -1 && val > n->right->data){
        return leftRotation(n);
    }
    if(bf > 1 && val > n->left->data){
        n->left = leftRotation(n->left);
        return rightRotation(n);
    }
    if(bf < -1 && val < n->right->data){
        n->right = rightRotation(n->right);
        return leftRotation(n);
    }

    return n;
}

Node *minNode(Node *n){
    Node *curr = n;

    while(curr->left != NULL){
        curr = curr->left;
    }

    return curr;
}

Node *maxNode(Node *n){
    Node *curr = n;

    while(curr->right != NULL){
        curr = curr->right;
    }

    return curr;
}

Node *deleteNode(Node *root, int val){
    if(root == NULL){
        return root;
    }

    if(val < root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        if((root->left == NULL) || (root->right == NULL)){
            Node *temp = root->left ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp; // 
            }
            free(temp);
        }
        else{
            Node *temp = minNode(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if(root == NULL) return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int bf = balanceFactor(root);
    if(bf > 1 && balanceFactor(root->left) >= 0){ // LL
        return rightRotation(root);
    }
    if(bf > 1 && balanceFactor(root->left) < 0){ // LR
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    if(bf < -1 && balanceFactor(root->right) <= 0){ // RR
        return leftRotation(root);
    }
    if(bf < -1 && balanceFactor(root->right) > 0){ // RL
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

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

int main(){
    Node *root = NULL; // 20,15,10,12,30,31,29,28
    
    int data[] = {20,15,10,12,30,31,29,28};
    for(int i=0; i<sizeof(data)/sizeof(data[0]); i++){
        root = insertNode(root, data[i]);
    }

    printf("Inorder traversal of the given tree:\n");
    inOrder(root);
    printf("\n");

    root = deleteNode(root, 20);
    root = deleteNode(root, 30);

    printf("Inorder traversal of the given tree:\n");
    inOrder(root);
    printf("\n");

    return 0;
}