#include<stdio.h>
#include<stdlib.h>
typedef struct NODE
{
	    int data;
	        struct NODE *next;
}node;
node *front=NULL,*rear=NULL,*temp;
void create()
{
	    node *newnode;
	        newnode=(node*)malloc(sizeof(node));
		    printf("\nEnter the node value : ");
		        scanf("%d",&newnode->data);
			    newnode->next=NULL;
			        if(rear==NULL)
					    front=rear=newnode;
				    else
					        {
							        rear->next=newnode;
								        rear=newnode;
									    }
				        
				        rear->next=front;
}
void display()
{
	    temp=front;
	        if(front==NULL)
			        printf("Empty\n");
		    else
			        {
					        printf("\n");
						        for(;temp!=rear;temp=temp->next)
								            printf("%d->",temp->data);
							            printf("%d->END\n",temp->data);
								        }
}
int main()
{
	    int ch;
	        create();
		    for(;;)
			        {
					        printf("To enter more data press 1 or press 0 to exit\n");
						        scanf("%d",&ch);
							        if(ch==0)
									            break;
								        else
										            create();
									    }
		        display();
}
