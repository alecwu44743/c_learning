#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char name[100];
    char id[100];
    int grade;
    struct student *next;
};
typedef struct student student;

student *head = NULL;

void print_students(){
    student *start = head;

    if(start == NULL){
        printf("Student list is empty.\n");
    }
    else{
        while(start != NULL){
            printf("Name: %s , ID:%s , Grade: %d\n", start->name, start->id, start->grade);
            start = start->next;
        }
    }
}

void append_student(){
    student *start = head;
    student *newStudent;

    newStudent = (student *)malloc(sizeof(student));

    printf("Name: ");
    scanf("%s", newStudent->name);
    printf("\nID: ");
    scanf("%s", newStudent->id);
    printf("\nGrade: ");
    scanf("%d", &newStudent->grade);

    if(start == NULL){
        newStudent->next = NULL;
        head = newStudent;
    }
    else{
        while(start->next != NULL){
            start = start->next;
        }
        newStudent->next = NULL;
        start->next = newStudent;
    }

}

void delete_student(){
    student *start = head;
    student *to_delete, *prev, *curr;

    char _id[100];
    printf("Enter student ID: ");
    scanf("%s", _id);

    if(strcmp(start->id, _id) == 0){
        to_delete = start;
        start = start->next;
        free(to_delete);
    }
    else{
        prev = start;
        curr = start->next;

        while(curr != NULL && strcmp(curr->id, _id) != 0){
            prev = curr;
            curr = curr->next;
        }

        if(curr == NULL){
            printf("Student not found QQ.\n");
        }
        else{
            to_delete = curr;
            prev->next = curr->next;
            free(to_delete);
        }
    }

    head = start;
}

int main(){
    int choice;
    while(1){
        printf("\n1. Print students\n2. Append student\n3. Delete student\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                print_students();
                break;
            case 2:
                append_student();
                break;
            case 3:
                delete_student();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
}
