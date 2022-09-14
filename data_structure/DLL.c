// Doubly Linked List

#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
    struct node* prev;
};
typedef struct node node;

node* head = NULL;


void push_node(int data){
    node* start = head;

    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = data;
    newNode->next = start;
    newNode->prev = NULL;

    if(start != NULL){
        start->prev = newNode;
    }

    head = newNode;
}


void insertAfter(node* prevNode, int data){
    if(prevNode == NULL){
        printf("Previous node cannot be NULL.\n");
        return;
    }

    node* newNode = (node*) malloc(sizeof(node));
    newNode->val = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if(newNode->next != NULL){
        newNode->next->prev = newNode;
    }
}


void append(int data){
    node* newNode = (node*) malloc(sizeof(node));
    node* last = head;

    newNode->val = data;
    newNode->next = NULL;

    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = newNode;
    newNode->prev = last;
}


void print_list(){
    node* last = NULL;

    printf("\nTraversal in forward direction \n");
    while(head != NULL){
        printf("%d ", head->val);
        last = head;
        head = head->next;
    }

    printf("\nTraversal in reverse direction \n");
    while(last != NULL){
        printf("%d ", last->val);
        last = last->prev;
    }    

    printf("\n");
}


int main(){
    append(6);
    push_node(7);

    push_node(1);
    append(4);
    insertAfter(head->next, 8);

    printf("Created DLL is: ");
    print_list();
}