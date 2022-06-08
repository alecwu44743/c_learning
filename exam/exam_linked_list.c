#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* head = NULL;

void print_list(){
    Node *np = head;

    if(np == NULL){
        printf("List is empty.\n");
    }
    else{
        while(np != NULL){
            printf("%d--> ", np->data);
            np = np->next;
        }
        printf("NULL\n");
    }
}

void insert_list(int val){
    Node *start = head;
    Node *newNode, *prev, *curr;

    newNode = (Node *)malloc(sizeof(Node));

    newNode->data = val;
    newNode->next = NULL;

    prev = NULL;
    curr = start;

    while(curr != NULL && val > curr->data){
        prev = curr;
        curr = curr->next;
    }

    if(prev == NULL){
        newNode->next = start;
        start = newNode;
    }
    else{
        prev->next = newNode;
        newNode->next = curr;
    }

    head = start;
}

void delete_list(int val){
    Node *start = head;
    Node *temp, *prev, *curr;

    if(val == start->data){
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
            printf("%d not found.\n", val);
        }
        else{
            temp = curr;
            prev->next = curr->next; 
            free(temp);
        }
    }

    head = start;
}

// search the element by recursional way
int search_recursive(Node *head, int val){
    if(head == NULL){
        return false;
    }

    if(head->data == val){
        return true;
    }

    return search_recursive(head->next, val);
}

void reverse_list(){
    Node *prev, *curr, *next;

    prev = NULL;
    curr = head;
    next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    head = prev;
}

int main(){
    insert_list(10);
    print_list();

    insert_list(20);
    print_list();

    insert_list(15);
    print_list();

    insert_list(50);
    print_list();

    insert_list(45);
    print_list();

    delete_list(15);
    print_list();

    delete_list(1220);
    print_list();

    delete_list(45);
    print_list();

    reverse_list();
    print_list();
}