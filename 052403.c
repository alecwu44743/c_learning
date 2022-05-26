
#include<stdio.h>
#include<stdlib.h>


typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
} node;

node *current = NULL;

void insertion(node*current,int val)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    while(current!=NULL)
    {
        if(val>current->data)
        {
            current = current->right;
        }
        else if (val<current->data)
        {
            current = current->left;
        }
    }
    if(current==NULL)
    {
        current = newnode;
    }  
}

int search(node* current,int val)
{
    while(current!=NULL)
    {
        if (current->data != val && current->data < val)
        {
            current = current->right;
            if(current->data == val)
            {
                return 1;
            }
        }
        else if(current->data != val && current->data>val)
        {
            current = current->left;
            if(current->data == val)
            {
                return 1;
            }
        }
    }
    return 0;
}


void print(node* current)
{
    int c = 1;
    if(current != NULL)
    {
        print(current->left);
        if(c==1)
        {
            printf("%d", current->data);
            c = 0;
        }
        else
        {
            printf(" %d",current->data);
        }
        print(current->right);  
    }
    printf("\n");
}

int main()
{
    int mode,val;
    while(scanf("%d",&mode)&&mode!=0)
    {
        if(mode==1)
        {
            scanf("%d", &val);
            insertion(current, val);
        }
        if(mode==2)
        {
            scanf("%d", &val);
            insertion(current, val);
        }
        if(mode==3)
        {

        }
        if(mode==4)
        {
            scanf("%d", &val);
            if(search(current,val)==1)
            {
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        if(mode==5)
        {
            print(current);
        }
    }
    return 0;
}