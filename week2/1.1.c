#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	int data;
	struct NODE *next;
}node;
node *start;
int count;
void create()
{
	node *nw,*current;
	int ch;
	do
	{
		nw=(node*)malloc(sizeof(node));
		printf("Enter the data\n");
		scanf("%d",&nw->data);
		nw->next=NULL;
		if(start==NULL)
		{
			start=nw;
			current=nw;
	
		}
		else
		{
			current->next=nw;
			current=nw;
		}
		count++;
		printf("Enter 1 to enter another data or 0 to exit\n");
		scanf("%d",&ch);
	}while(ch!=0);
	current->next=start;
}
void insert(int data, int n)
{
    int i;
    node *temp1  = (node*) malloc(sizeof(node));
    temp1->data = data;
    temp1->next = temp1;
    if(n == 1)
    {
        temp1->next = start->next;
        start->next = temp1;
        return;
    }
    node* temp2=start;
    for(i=0;i<n-2;i++)
	   temp2 = temp2->next;
    if(n==count)
    {
	    temp2->next = start->next;
	    start->next = temp2;
	    start=temp2;
    }
}
void display()
{
	node *temp=start;
	while(temp->next!=start)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("END\n");
}
int main()
{
	int i,n,data;
	create();
	printf("Enter the position to insert data\n");
	scanf("%d",&n);
	printf("Enter the data\n");
	scanf("%d",&data);
	insert(data,n);
	display();
}
