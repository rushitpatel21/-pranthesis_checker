// 190630107063 - DS Practical 7
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

struct LL
{
	int info;
	struct LL *next;
} list;

struct LL *first=NULL,*current=NULL;

struct LL *create_node(void);
void insert_func(int);
void delete_func(int);
void display_func(void);
void delay(int milliseconds);

int main()
{
	int n,ch;
	printf("***** Options *****\n1. Insert\n2. Delete\n3. Display\n4. Exit\n ");
	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		 {
			case 1:
				printf("\nEnter the Element : ");
				scanf("%d",&n);
				insert_func(n);
				printf("Successfully Inserted Element !!");
				delay(1000);
				system("cls");
				printf("***** Options *****\n1. Insert\n2. Delete\n3. Display\n4. Exit\n ");
				break;
			case 2:
				printf("\nEnter the Element to delete : ");
				scanf("%d",&n);
				delete_func(n);
				printf("Successfully Deleted Element !!");
				delay(1000);
				system("cls");
				printf("***** Options *****\n1. Insert\n2. Delete\n3. Display\n4. Exit\n ");
				break;
			case 3:
				printf("\nContents of linked list : \n");
				display_func();
				break;
			case 4:
				exit(0);
            default:
                printf("Enter valid Option");
		};
	}
	getch();
}

struct LL *create_node(void)
{
	struct LL *temp;
	temp=(struct LL*) malloc(sizeof(struct LL));
	temp->next=NULL;
	return temp;
}

void insert_func(int n)
{
	struct LL *temp;
	if(first == NULL)
	{
		first=create_node();
		first->info=n;
		first->next=NULL;
		current=first;
	}
	else
	{
		temp=create_node();
		temp->info=n;
		current->next=temp;
		current=temp;
	}
}

void display_func(void)
{
	struct LL *start;
	start=first;
	while(start!=NULL)
	{
		printf("%d ",start->info);
		start=start->next;
	}
}

void delete_func(int n)
{
	struct LL *temp,*prev;
	prev=temp=first;
	if(temp->info == n)
		first=temp->next;
	else
	{
		while(temp!=NULL)
		{
			if(temp->info == n)
				break;
			prev=temp;
			temp=temp->next;
		}
	}
	prev->next=temp->next;
	free(temp);
}

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
