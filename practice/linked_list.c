#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node *head = NULL;

void print_list(){
    node *start = head;

    if(start == NULL){
        printf("List is empty.\n");
    }
    else{
        while(start != NULL){
            printf("%d--> ", start->data);
            start = start->next;
        }
        printf("NULL\n");
    }
}

void insert_node(int val){
    node *newNode, *prev, *curr;
    node *start = head;

    newNode = (node *)malloc(sizeof(node));

    if(newNode == NULL){
        printf("Out of memory.\n");
    }

    newNode->data = val;
    newNode->next = NULL;

    prev = NULL, curr = start;

    while(curr != NULL && val >= curr->data){
        if(val == curr->data){
            free(newNode);
            printf("%d is duplicated.\n", val);

            return;
        }

        prev = curr;
        curr = curr->next;
    }

    if(prev == NULL){
        newNode->next = curr;
        start = newNode;
    }
    else{
        prev->next = newNode;
        newNode->next = curr;
    }

    head = start;
}

void delete_node(int val){
    node *prev, *curr;
    node *start, *temp;

    start = head;

    if(val == start->data){
        temp = start;
        start = start->next;
        free(temp);

        head = start;
        return;
    }

    prev = start;
    curr = start->next;

    while(curr != NULL && curr->data != val){
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){
        printf("%d not found.\n", val);
    }
    else{
        temp = curr;
        prev->next = curr->next;

        free(temp);
    }
}

int main(){
    insert_node(10);
    print_list();

    insert_node(5);
    print_list();

    insert_node(39);
    print_list();

    insert_node(31);
    print_list();

    insert_node(26);
    print_list();

    insert_node(40);
    print_list();

    insert_node(39);
    print_list();

    insert_node(66);
    print_list();

    insert_node(74);
    print_list();

    insert_node(72);
    print_list();

    printf("\n");

    delete_node(100);
    print_list();

    delete_node(72);
    print_list();

    delete_node(5);
    print_list();

    delete_node(39);
    print_list();
}