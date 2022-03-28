#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node *stackTop = NULL;

void print_stack(){
    Node *start = stackTop;
    if(start == NULL){
        printf("Stack is empty.\n");
    }
    else{
        while(start != NULL){
            printf("%d--> ", start->data);
            start = start->next;
        }
    }

    printf("NULL\n");
}

void stack_push(int val){
    Node *top = stackTop;
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Out of memory.\n");
    }
    else{
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    stackTop = top;
}

void stack_pop(){
    Node *top = stackTop;
    Node *temp;
    int Val;

    if(top == NULL){
        printf("Stack is empty.\n");
    }
    else{
        temp = top;
        top = top->next;
        Val = temp->data;
        free(temp);

        printf("Pop: %d\n", Val);
    }

    stackTop = top;
}

int main(){
    stack_push(10);
    print_stack();

    stack_push(20);
    print_stack();

    stack_push(1220);
    print_stack();

    stack_push(40);
    print_stack();

    stack_pop();
    print_stack();

    stack_pop();
    print_stack();
}