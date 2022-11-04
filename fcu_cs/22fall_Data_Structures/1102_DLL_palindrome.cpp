#include <iostream>

using namespace std;


struct node{
    char data;
    node *next;
    node *prev;
};


void append(node **head, char c){
    node *new_node = new node;
    new_node->data = c;
    new_node->next = (*head);
    new_node->prev = NULL;

    if((*head) != NULL){
        (*head)->prev = new_node;
    }
    (*head) = new_node;
}

void print(node *head){
    node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isPalindrome(node *left){
    if(left == NULL){
        return true;
    }

    node *right = left;
    while(right->next != NULL){
        right = right->next;
    }

    while(left != right){
        if(left->data != right->data){
            return false;
        }
        left = left->next;
        right = right->prev;
    }

    return true;
}


int main(){
    // node *head = NULL;
    // string s;
    // cin >> s;
    // for(int i = 0; i < s.length(); i++){
    //     append(&head, s[i]);
    // }
    // // print(head);
    // if(isPalindrome(head)){
    //     cout << "Yes" << endl;
    // }else{
    //     cout << "No" << endl;
    // }

    int num;
    string str;

    while(cin >> num){
        for(int i = 0; i < num; i++){
            cin >> str;
            node *head = NULL;
            for(int j = 0; j < str.length(); j++){
                append(&head, str[j]);
            }
            if(isPalindrome(head)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }

    return 0;
}