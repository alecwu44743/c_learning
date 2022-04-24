#include "stdlib.h"
#include "stdio.h"

typedef struct node{
    int data;
    struct node *next;
}Node;

void print_list(Node *start){
    if(start == NULL){
        printf("List is empty\n");
    }
    else{
        while(start != NULL){ // while loop to print all the nodes
            printf("%d--> ", start->data);
            start = start->next;
        }
        printf("NULL\n");
    }
}

Node* addNode(Node *start, int val){
    Node *newNode, *prev, *curr;

    newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL){
        printf("Out of memory.\n");
        return NULL;
    }

    newNode->data = val; // Assign data
    newNode->next = NULL; // Assign next

    prev = NULL, curr = start; // Initialize prev and curr

    while(curr != NULL && curr->data < val){ // find the position to insert
        prev = curr;
        curr = curr->next;
    }

    if(prev == NULL){ // insert at the beginning
        newNode->next = start;
        start = newNode;
    }
    else{ // insert in the middle or at the end
        prev->next = newNode;
        newNode->next = curr;
    }

    return start;
}

Node* deleteNode(Node *start, int val){
    Node *temp, *prev, *curr;

    if(val == start->data){ // delete the first node
        temp = start;
        start = start->next;

        free(temp);
        return start;
    }

    prev = start; // Initialize prev and curr
    curr = start->next; // curr points to the second node

    while(curr != NULL && val != curr->data){ // find the node to delete
        prev = curr;
        curr = curr->next;
    }

    if(curr == NULL){ // node not found
        printf("%d not found.\n", val);
    }
    else{ // delete the node
        // if(curr->data == val){
            temp = curr; // store the node to be deleted
            prev->next = curr->next; // remove the node from the list
            free(temp); // free the memory
        // }
    }

    return start;
}

int main(){
    Node *head;
    head = NULL;

    head = addNode(head, 10);
    print_list(head);

    head = addNode(head, 20);
    print_list(head);

    head = addNode(head, 40);
    print_list(head);

    head = addNode(head, 30);
    print_list(head);

    head = deleteNode(head, 50);
    print_list(head);

    head = deleteNode(head, 10);
    print_list(head);

    head = deleteNode(head, 30);
    print_list(head);
}