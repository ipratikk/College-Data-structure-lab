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
void search(int x)
{
	    int count=0,check=0;
	        temp=front;
		    if(front==NULL)
			            printf("Empty\n");
		        else
				    {
					            for(;temp!=rear;temp=temp->next)
							            {
									                if(temp->data==x)
												            {
														                    check=1;
																                    printf("%d found at %d position\n",x,count);
																		                    break;
																				                }
											            else if(temp->next->data==x)
													                {
																                check=1;
																		                printf("%d found at %d position\n",x,++count);
																				                break;
																						            }
												                else
															                count++;
														        }
						            if(check==0)
								                printf("Number not found\n");
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
		        printf("Enter the number you want to search\n");
			    scanf("%d",&ch);
			        search(ch);
}
