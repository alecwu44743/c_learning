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

node *front = NULL;
node *rear = NULL;

void print_queue(){
    node *start = front;

    if(start == NULL){
        printf("Queue is empty.\n");
    }
    else{
        while(start!= NULL){
            printf("%d--> ", start->data);
            start = start->next;
        }
        printf("NULL\n");
    }
}

int search_queue(int val){
    node *start = front;

    while(start != NULL){
        if(start->data == val){
            printf("%d is duplicated\n", val);
            return 1;
        }
        start = start->next;
    }

    return 0;
}

void enQueue(int val){
    if(search_queue(val) == 1) return;

    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if(front ==  NULL){
        front = newNode;
    }
    else{
        rear->next = newNode;
    }

    rear = newNode;
}

void deQueue(){
    node *temp;

    if(front == NULL){
        printf("Queue is empty.\n");
    }
    else{
        int val = front->data;
        temp = front;
        front = front->next;

        free(temp);
        printf("Dequeue: %d\n", val);

        if(front ==  NULL) rear = NULL;
    }
}

int main(){
    enQueue(10);
    print_queue();

    enQueue(20);
    print_queue();

    enQueue(30);
    print_queue();

    enQueue(100);
    print_queue();

    deQueue();
    print_queue();

    deQueue();
    print_queue();
}