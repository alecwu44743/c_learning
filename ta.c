#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node node;

node* head = NULL;

void print_list(){
    if(head == NULL){
        printf("List is empty.\n");
    }
    else{
        node *start = head;

        while(start != NULL){
            printf("%d--> ", start->data);
            start = start->next;
        }
        printf("NULL\n");
    }
}

void insert_node(int val){
    node* newNode;

    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{
        node* start = head;
        while(start->next != NULL){
            start = start->next;
        }
        start->next = newNode;
    }
}

void delete_node(int val){
    node *start = head, *prev, *curr, *temp;

    if(start->data == val){
        temp = start;
        start = start->next;
        free(temp);
    }
    else{
        prev = start;
        curr = start->next;

        while(curr != NULL && curr->data != val){
            prev = curr;
            curr = curr->next;
        }

        if(curr == NULL){
            printf("Not found QQ.\n");
        }
        else{
            temp = curr;
            prev->next = curr->next;
            free(temp);
        }
    }

    head = start;
    
}


int main(){
    // test linked list
    insert_node(1);
    insert_node(2);
    insert_node(3);
    insert_node(4);
    insert_node(5);
    insert_node(6);
    print_list();

    delete_node(3);
    print_list();

    insert_node(10);
    print_list();

    delete_node(1);
    print_list();
}
