#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	    int data;
	        struct node *next;
		    struct node *prev;
}node;
node *start,*nw,*tmp;
int size;
void create()
{
	    node *nw;
	        nw=(node*)malloc(sizeof(node));
		    printf("Enter data\n",&nw->data);
		        nw->next=NULL;
			    nw->prev=NULL;
}
void append()
{
	    create();
	        if(start==NULL)
			    {
				            start=nw;
					            tmp=start;
						        }
		    else
			        {
					        tmp->next=nw;
						        nw->prev=tmp;
							        nw->next=start;
								        start->prev=nw;
									        tmp=nw;
										    }
		        size++;
}
void display()
{
	    node *tmp2=start;
	        while(tmp2->next!=start)
			    {
				            printf("%d->",tmp2->data);
					            tmp2=tmp2->next;
						        }
		    printf("END\n");
}
void search()
{
	    int count=0,val;
	        node *tmp2=start;
		    printf("Enter value to search\n");
		        scanf("%d",&val);
			    while(tmp2->next!=start)
				        {
						        if(tmp2->data==val)
								            printf("%d present at %d position",val,count);
							        count++;
								        tmp2=tmp2->next;
									    }
}
void insert(int n)
{
	    int i;
	        node *tmp2=start;
		    create();
		        if(n==1)
				    {
					            nw->next=start;
						            nw->prev=start->prev;
							            start->prev->next=nw;
								            start->prev=nw;
									            start=nw;
										        }
			    else if(n==size)
				        {
						        nw->next=start;
							        nw->prev=start->prev;
								        start->prev->next=nw;
									        start->prev=nw;
										    }
			        else
					    {
						            for(i=0;i<n+1;i++)
								                tmp2=tmp2->next;
							            nw->next=tmp2;
								            nw->prev=tmp2->prev;
									            tmp2->prev->next=nw;
										            tmp2->prev=nw;
											        }
				    size++;
}
void delete(int n)
{
	    node *tmp2=start,tmp3;
	        int i;
		    if(n==1)
			        {
					        start->prev->next=start->next;
						        start=start->next;
							        start->prev=tmp2->prev;
								        free(tmp2);
									        tmp2=start;
										    }
		        if(n==size)
				    {
					            start->prev=start->prev->prev;
						            tmp2=start->prev;
							            start->prev->prev->next=start;
								            free(tmp2);
									            tmp2=start;
										        }
			    else
				        {
						        for(i=0;i<n;i++)
								            tmp2=tmp2->next;
							        tmp3=tmp2->prev;
								        tmp3->prev->next=tmp2;
									        tmp2->prev=tmp3->prev;
										        free(tmp3);
											    }
			        size--;
}
void reverse()
{
	    printf("The linked list in reversed order is->\n");
	        node *tmp2=start->prev;
		    while(tmp2!=start)
			        {
					        printf("%d->",tmp2->data);
						        tmp2=tmp2->prev;
							    }
		        printf("%d->END\n",tmp2->data);
}
int main()
{
	    size=0;
	        int ch,x;
		    printf("Create a linked list\n");
		        for(;;)
				    {
					            printf("1.Enter data\n");
						            printf("0.Exit\n");
							            scanf("%d",&ch);
								            if(ch==0)
										                break;
									            else
											                append();
										        }
			    for(;;)
				        {
						        printf("1.Display the list\n");
							        printf("2.Insert a value at the begining\n");
								        printf("3.Insert a value at the end\n");
									        printf("4.Insert a value at any posiiton");
										        printf("5.Count the number of nodes\n");
											        printf("6.Delete a value at the begining\n");
												        printf("7.Delete a value at the end\n");
													        printf("8.Delete a value at any position\n");
														        printf("9.Display the reverse of the list\n");
															        printf("0.Exit\n");
																        scanf("%d",&ch);
																	        if(ch==0)
																			            break;
																		        else
																				        {
																						            switch(ch)
																								                {
																											                case 1:
																														                    display();
																																                        break;
																																			                case 2:
																																			                    insert(1);
																																					                        break;
																																								                case 3:
																																								                    insert(size);
																																										                        break;
																																													                case 4:
																																													                    printf("Enter the position to insert the element\n");
																																															                        scanf("%d",&x);
																																																		                    insert(x);
																																																				                        break;
																																																							                case 5:
																																																							                    printf("The number of nodes are :- %d",size);
																																																									                        break;
																																																												                case 6:
																																																												                    delete(1);
																																																														                        break;
																																																																	                case 7:
																																																																	                    delete(size);
																																																																			                        break;
																																																																						                case 8:
																																																																						                    printf("Enter the position to delete the element\n");
																																																																								                        scanf("%d",&x);
																																																																											                    insert(x);
																																																																													                        break;
																																																																																                case 9:
																																																																																                    reverse();
																																																																																		                        break;
																																																																																					                case 0:
																																																																																					                    printf("Thank You!\n");
																																																																																							                        exit();
																																																																																										                default:
																																																																																										                    printf("Invalid Choice\n");
																																																																																												                        break;
																																																																																															            }
																							            }
																			    }
}
