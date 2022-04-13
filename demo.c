#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	char name[100];
	char id[100];
	int grade;
	struct student *next;
};
typedef struct student student;

struct student *new_student(void)
{
	struct student *newnode;
	newnode = (struct student*)malloc(sizeof(struct student));
	newnode->next = NULL;
	return newnode;
}

int main()
{
	int a = 1;
	char sid[100];
	student *first;
	student *cur = NULL;
	student *newstudent;
	student *node;
	student *temp;
	while(a!=0)
	{
		printf("新增學生請按(1)，搜尋學生請按(2)，刪除學生請按(3)，輸出學生名單請按(4)，離開請按(0)：");
		scanf("%d" ,&a);
		switch(a)
		{
			case 1://add
				if(cur == NULL)
				{
					first = new_student();
					printf("Name: ");
					scanf("%s", &first->name);
					printf("ID: ");
					scanf("%s" ,&first->id);
					printf("Grade: ");
					scanf("%d" ,&first->grade);
					cur = first;
				}
				else
				{
					newstudent = new_student();
					printf("Name: ");
					scanf("%s", &newstudent->name);
					printf("ID: ");
					scanf("%s" ,&newstudent->id);
					printf("Grade: ");
					scanf("%d" ,&newstudent->grade);
					cur->next = newstudent;
					cur = cur->next;
				}
				break;
			case 2://search
				node = first;
				printf("輸入要搜尋的學生學號：");
				scanf("%s" ,&sid);
				while(node!=NULL)
				{
					if(strcmp(node->id,sid)==0)
					{
						printf("找到了，Name: %s , ID: %s , Grade: %d\n" ,node->name ,node->id ,node->grade);
						break;
					}
					node = node->next;
				}
				if(node==NULL)
				{
					printf("找不到\n");
				}
				break;
			case 3://delete
				node = first;
				printf("輸入要刪除的學生學號：");
				scanf("%s" ,&sid);
				while(node!=NULL)
				{
					if(strcmp(node->id,sid)==0)
					{
						temp->next = node->next;
						free(node->next);
						printf("刪除完成\n");
						break;
					}
					temp = node;
					node = node->next;
				}
				if(node==NULL)
				{
					printf("找不到\n");
				}
				break;
			case 4://printf
				node = first;
				while(node!=NULL)
				{
					printf("Name: %s , ID:%s , Grade: %d\n" ,node->name ,node->id ,node->grade);
					node = node->next;
				}
				break;
			case 0://leave
				a=0;
				break;
			default:
				printf("新增學生請按(1)，搜尋學生請按(2)，刪除學生請按(3)，輸出學生名單請按(4)，離開請按(0)。");
				break;
		}
	}
}