#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* stackTop = NULL;

void print_stack(){
    Node *start = stackTop;
    if(start == NULL){
        printf("Stack is empty\n");
    }
    else{
        while(start != NULL){
            printf("%d--> ", start->data);
            start = start->next;
        }
        printf("NULL\n");
    }
}

void push(int val){
    Node* top = stackTop;
    Node* newNode;
    newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Out of memory\n");
    }
    else{
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    stackTop = top;
}

void pop(){
    Node* top = stackTop;
    Node* temp;

    if(top == NULL){
        printf("Stack is empty.\n");
    }
    else{
        int pop_val;
        temp = top;
        pop_val = temp->data;
        top = top->next;

        free(temp);
        printf("Pop: %d\n", pop_val);
    }

    stackTop = top;
}

int main(){
    push(10);
    print_stack();

    push(20);
    print_stack();

    push(30);
    print_stack();

    push(40);
    print_stack();

    push(1220);
    print_stack();

    pop();
    print_stack();

    pop();
    print_stack();
}