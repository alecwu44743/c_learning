// 374 - Big Mod
// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=310
// Reference: https://hwchang0417.wordpress.com/2018/12/17/uva-374-big-mod/amp/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    long long int data;
    struct node* next;
}Node;

Node* head = NULL;

void print_list(){
    Node *start = head;

    // cannot end with a space
    while(start != NULL){
        printf("%lld\n", start->data);
        start = start->next;
    }
}

void insert_list(long long int val){
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

long long int b_pow_p_mod_m(long long int b, long long int p, long long int m){
    int ans = 1;
    long long int x = b%m;

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