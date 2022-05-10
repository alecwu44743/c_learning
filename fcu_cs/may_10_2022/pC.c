#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    unsigned int data;
    struct node* next;
}Node;

Node* head = NULL;

void print_list(){
    Node *np = head;

    if(np == NULL){
        // printf("List is empty.\n");
        return;
    }
    else{
        while(np != NULL){
            printf("%u\n", np->data);
            np = np->next;
        }
        // printf("NULL\n");
    }
}

void insert_list(unsigned int val){
    Node *start = head;
    Node *newNode, *prev, *curr;

    newNode = (Node *)malloc(sizeof(Node));

    newNode->data = val;
    newNode->next = NULL;

    prev = NULL;
    curr = start;

    while(curr != NULL){
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

unsigned int b_mod_m(char *b, unsigned int m){
    unsigned int val = 0;

    for(int i=0; i<strlen(b); i++){
        val = val*10 + (b[i] - '0');
        val %= m;
    }

    return val;
}

void b_pow_p_mod_m(char *b, unsigned int p, unsigned int m){
    unsigned int ans = b_mod_m(b, m);
    unsigned int mVal = ans;

    for(unsigned int i=1; i<p; i++){
        ans = (ans*mVal) % m;
    }

    insert_list(ans);
}


int main(){
    char b[100];
    unsigned int p;
    unsigned int m;

    while(scanf("%s %u %u", b, &p, &m) != EOF){
        getchar();

        if(b[0]=='0' && p==0 && m==0){
            break;
        }
        b_pow_p_mod_m(b, p, m);
    }

    print_list();

}