#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    unsigned int data;
    struct node* next;
}Node;

Node* head = NULL;

void print_list(){
    // if(head == NULL){
    //     printf("List is empty.\n");
    // }
    // else{
        int p = 0;
        Node *start = head;

        // cannot end with a space
        while(start != NULL){
            if(p == 0){
                printf("%d", start->data);
                p++;
            }
            else{
                printf("\n%d", start->data);
            }
            start = start->next;
        }
        // printf("NULL");
    // }
    // printf("\n");
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

// unsigned int b_mod_m(char *b, unsigned int m){
//     unsigned int val = 0;

//     for(int i=0; i<strlen(b); i++){
//         val = val*10 + (b[i] - '0');
//         val %= m;
//     }

//     return val;
// }

long long int b_pow_p_mod_m(long long int b, long long int p, long long int m){
    int ans = 1;
    int x = b%m;

    while(p > 0){
        if(p&1){
            ans = (ans * x) % m;
        }

        x = (x * x) % m;
        p >>= 1;
    }

    return ans % m;
}


int main(){
    long long int  b;
    long long int  p;
    long long int  m;

    while(scanf("%lld %lld %lld", &b, &p, &m) != EOF){
        getchar();

        if(b==0 && p==0 && m==0){
            break;
        }
        
        // printf("%lld\n", b_pow_p_mod_m(b, p, m));
        insert_list(b_pow_p_mod_m(b, p, m));

    }

    print_list();

}