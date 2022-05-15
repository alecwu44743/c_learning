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

node *top = NULL;

void print_stack(){
    node *start = top;

    if(start == NULL){
        printf("Stack is empty.\n");
    }
    else{
        while(start != NULL){
            printf("%d--> ", start->data);
            start = start->next;
        }
        printf("NULL\n");
    }
}

int search_stack(int val){
    node *start = top;

    while(start != NULL){
        if(start->data == val){
            printf("%d is duplicated\n", val);
            return 1;
        }

        start = start->next;
    }

    return 0;
}

void push_stack(int val){
    if(search_stack(val) == 1) return;

    node *newNode;

    newNode = (node *)malloc(sizeof(node));

    newNode->data = val;
    newNode->next = top;

    top = newNode;
}

void pop_stack(){
    node *tp = top;
    node *temp;
    int val;

    if(tp == NULL){
        printf("Stack is empty.\n");
        return;
    }
    else{
        temp = tp;
        tp = tp->next;
        val = temp->data;
        free(temp);

        printf("pop: %d\n", val);
    }

    top = tp;
}

int main(){
    push_stack(10);
    print_stack();

    push_stack(20);
    print_stack();

    push_stack(1);
    print_stack();

    push_stack(10);
    print_stack();

    pop_stack();
    print_stack();

    pop_stack();
    print_stack();

    pop_stack();
    print_stack();

    push_stack(20);
    print_stack();

    push_stack(12);
    print_stack();

    push_stack(93);
    print_stack();

    push_stack(19);
    print_stack();

    push_stack(520);
    print_stack();
}