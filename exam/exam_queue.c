#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;

void print_queue(){
    Node* start = front;
    if(start == NULL){
        printf("Queue is empty.\n");
    }
    else{
        while(start != NULL){
            printf("%d--> ", start->data);
            start = start->next;
        }
        printf("NULL\n");
    }
}

void enqueue(int val){
    Node* newNode;
    newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Out of memory.\n");
    }
    else{
        newNode->data = val;
        newNode->next = NULL;

        if(front == NULL){
            front = newNode;
        }
        else{
            rear->next = newNode;
        }
        rear = newNode;
    }
}

void dequeue(){
    Node* temp;

    if(front == NULL){
        printf("Queue is empty.\n");
    }
    else{
        int dequeueVal = front->data;
        temp = front;
        front = front->next;

        free(temp);
        printf("Dequeue: %d\n", dequeueVal);

        if(front == NULL) rear = NULL;
    }
}

int main(){
    enqueue(10);
    print_queue();

    enqueue(20);
    print_queue();

    enqueue(30);
    print_queue();

    enqueue(40);
    print_queue();

    enqueue(50);
    print_queue();

    enqueue(1220);
    print_queue();

    dequeue();
    print_queue();

    dequeue();
    print_queue();
}