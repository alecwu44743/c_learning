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

node* head = NULL;

// print list
void print_list(){
    // if(head == NULL){
    //     printf("List is empty.\n");
    // }
    // else{
        int p = 0;
        node *start = head;

        // cannot end with a space
        while(start != NULL){
            if(p == 0){
                printf("%d", start->data);
                p++;
            }
            else{
                printf(" %d", start->data);
            }
            start = start->next;
        }
        // printf("NULL");
    // }
    printf("\n");
}


// #3 - searching list, return true if found
int search_list(int val){
    node *start = head;

    while(start != NULL){
        if(start->data == val){
            // printf("%d found.\n", val);
            return 1;
        }
        start = start->next;
    }
    // printf("%d not found.\n", val);
    return 0;
}


// #1 #2 - insert node at the beginning
void insert_node(int op, int val){
    if(search_list(val) == 1){
        print_list();
        return;
    }
    
    node* newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if(op == 1){
        head = newNode;
    }
    else{ // op == 2
        node *prev, *curr;
        prev = NULL;
        curr = head;

        while(curr != NULL && curr->data < val){
            prev = curr;
            curr = curr->next;
        }

        if(prev == NULL){
            newNode->next = head;
            head = newNode;
        }
        else{
            prev->next = newNode;
            newNode->next = curr;
        }
    }

    print_list();
}

void delete_list(int val){
    node *start = head;
    node *to_delete, *prev, *curr;

    if(val == start->data){
        head = start->next;
        free(start);
        print_list();
        return;
    }
    else{
        prev = start;
        curr = start->next;

        while(curr != NULL && curr->data != val){
            prev = curr;
            curr = curr->next;
        }

        if(curr == NULL){
            // printf("%d not found.\n", val);
            print_list();
            return;
        }
        else{
            to_delete = curr;
            prev->next = curr->next;
            free(to_delete);
            print_list();
        }
    }
}

int main(){
    int op;
    int val;

    while(scanf("%d", &op) && op > 0){
        if(op == 1){
            scanf("%d", &val);
            insert_node(1, val);
        }
        else if(op == 2){
            scanf("%d", &val);
            insert_node(2, val);
        }
        else if(op == 3){
            scanf("%d", &val);
            delete_list(val);
        }
        else if(op == 4){
            scanf("%d", &val);
            if(search_list(val) == 1){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
}