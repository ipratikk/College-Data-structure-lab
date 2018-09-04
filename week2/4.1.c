#include<stdio.h>
#include<stdlib.h>
    struct node {
	            struct node * prev;
		            int n;
			            struct node * next;
				        }* h, * temp, * temp1, * temp2, * temp4;
void insert2();
void traversebeg();
void delf();
void dellast();
void delany();
int count = 0;
int main() {
	    int ch;
	        h = NULL;
		    temp = temp1 = NULL;
		        printf("\n 1 - Insert");
			    printf("\n 2 - Delete first");
			        printf("\n 3 - Delete last");
				    printf("\n 4 - Delete any position");
				        printf("\n 0 - Display from beginning");
					    while (1) {
						            printf("\n Enter choice : ");
							            scanf("%d", & ch);
								            switch (ch) {
										            case 1:
												                insert2();
														            break;
															            case 2:
															                delf();
																	            break;
																		            case 3:
																		                dellast();
																				            break;
																					            case 4:
																					                delany();
																							            break;
																								            case 0:
																								                traversebeg();
																										            break;
																											            default:
																											                printf("\n Wrong choice menu");
																													        }
									        }
}
void create() {
	    int data;
	        temp = (struct node * ) malloc(1 * sizeof(struct node));
		    temp -> prev = NULL;
		        temp -> next = NULL;
			    printf("\n Enter value to node : ");
			        scanf("%d", & data);
				    temp -> n = data;
				        count++;
}
void insert2() {
	    if (h == NULL) {
		            create();
			            h = temp;
				            temp1 = h;
					        } else
							        create();
						    temp1 -> next = temp;
						        temp -> prev = temp1;
							    temp1 = temp;
}
void delf() {
	    if (h == NULL) {
		            printf("Linklist id empty");
			        } else {
					        temp1 = h;
						        h = h -> next;
							        free(temp1);
								        h -> prev = NULL;
									    }
}
void traversebeg() {
	    temp2 = h;
	        if (temp2 == NULL) {
			        printf("List empty to display \n");
				        return;
					    }
		    printf("\n Linked list elements from begining : ");
		        while (temp2 -> next != NULL) {
				        printf(" %d ", temp2 -> n);
					        temp2 = temp2 -> next;
						    }
			    printf(" %d ", temp2 -> n);
}
void dellast() {
	    if (h == NULL) {
		            printf("Linklist id empty");
			        } else {
					        temp1 = h;
						        while (temp1 -> next != NULL) {
								            temp1 = temp1 -> next;
									            }
							        temp2 = temp1;
								        temp1 -> prev -> next = NULL;
									        free(temp2);
										    }
}
void delany() {
	    int i = 1, pos;
	        printf("\n Enter position to be deleted : ");
		    scanf("%d", & pos);
		        temp2 = h;
			    if ((pos < 1) || (pos >= count + 1)) {
				            printf("\n Error : Position out of range to delete");
					            return;
						        }
			        if (h == NULL) {
					        printf("\n Error : Empty list no elements to delete");
						        return;
							    } else {
								            while (i < pos) {
										                temp2 = temp2 -> next;
												            i++;
													            }
									            if (i == 1) {
											                if (temp2 -> next == NULL) {
														                printf("Node deleted from list");
																                free(temp2);
																		                temp2 = h = NULL;
																				                return;
																						            }
													        }
										            if (temp2 -> next == NULL) {
												                temp2 -> prev -> next = NULL;
														            free(temp2);
															                printf("Node deleted from list");
																	            return;
																		            }
											            temp2 -> next -> prev = temp2 -> prev;
												            if (i != 1)
														                temp2 -> prev -> next = temp2 -> next; /* Might not need this statement if i == 1 check */
													            if (i == 1)
															                h = temp2 -> next;
														            printf("\n Node deleted");
															            free(temp2);
																        }
				    count--;
}

