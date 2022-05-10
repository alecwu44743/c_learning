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
int queueSize = 0;

void print_queue(){
    node *start = front;
    if(start == NULL){
        // printf("Queue is empty.\n");
        return;
    }
    else{
        while(start != NULL){
            printf("%d ", start->data);
            start = start->next;
        }
        // printf("NULL\n");
    }
}

int search_queue(int val){
    node *start = front;

    while(start != NULL){
        if(start->data == val){
            // printf("%d found.\n", val);
            return 1;
        }
        start = start->next;
    }

    return 0;
}

void inQueue(int val){
    if(search_queue(val) == 1 || queueSize == 5) return;

    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;

    newNode->next = NULL;

    if(front == NULL){
        front = newNode;
    }
    else{
        rear->next = newNode;
    }

    rear = newNode;
    queueSize++;
}

void deQueue(){
    node *temp;

    if(front == NULL){
        // printf("Queue is empty.\n");
        return;
    }
    else{
        int dequeueVal = front->data;
        temp = front;
        front = front->next;

        free(temp);
        printf("%d\n", dequeueVal);

        if(front == NULL) rear = NULL;
    }

    queueSize--;
}


int main(){
    int op;
    int val;

    while(scanf("%d", &op) != EOF && op > 0){
        if(op == 1){
            scanf("%d", &val);
            inQueue(val);
        }
        else if(op == 2){
            deQueue();
        }
        else if(op == 3){
            print_queue();
        }
    }
}