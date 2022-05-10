#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

int stackSize = 0;
node *stackTop = 0;

void print_stack(){
    node *start = stackTop;

    if(start == NULL){
        return;
    }
    else{
        while(start != NULL){
            printf("%d ", start->data);
            start = start->next;
        }
    }
}

int search_stack(int val){
    node *start = stackTop;

    while(start != NULL){
        if(start->data == val){
            // printf("%d found.\n", val);
            return 1;
        }
        start = start->next;
    }

    return 0;
}

void push_stack(int val){
    if(search_stack(val) == 1 || stackSize == 5) return;

    node *top = stackTop;
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;

    newNode->next = top;
    top = newNode;

    stackTop = top;
    stackSize++;
}

void pop_stack(){
    node *top = stackTop;
    node *temp;
    int Val;

    if(top == NULL){
        return;
    }
    else{
        temp = top;
        top = top->next;
        Val = temp->data;
        free(temp);

        printf("%d\n", Val);
    }

    stackTop = top;
    stackSize--;
}

int main(){
    int op;
    int val;

    while(scanf("%d", &op) != EOF && op > 0){
        if(op == 1){
            scanf("%d", &val);
            push_stack(val);
        }
        else if(op == 2){
            pop_stack();
        }
        else if(op == 3){
            print_stack();
        }
    }
}