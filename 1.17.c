#include <stdio.h>
#include <stdlib.h>
    int ** create(int m, int n) {
	            int ** p, i;
		            p = (int ** ) malloc(m * sizeof(int * ));
			            for (i = 0; i < n; i++)
					                p[i] = (int * ) malloc(n * sizeof(int));
				        }
void display(int m, int n, int ** p) {
	    int i, j;
	        for (i = 0; i < m; i++) {
			        for (j = 0; j < n; j++)
					            printf("%d ", p[i][j]);
				        printf("\n");
					    }
}
int main() {
	    int m, n, i, j, lim, inp, check = 0, ** p;
	        printf("Enter the array size :");
		    scanf("%d%d", & m, & n);
		        p = create(m, n);
			    int range[m][2], limit[m];
			        lim = m * n;
				    for (i = 0; i < m; i++) {
					            printf("Row %d range\nStart : ", i + 1);
						            scanf("%d", & range[i][0]);
							            printf("End : ");
								            scanf("%d", & range[i][1]);
									            limit[i] = 0;
										        }
				        i = 0;
					    while (i < lim) {
						            check = 0;
							            printf("Enter age :");
								            scanf("%d", & inp);
									            for (j = 0; j < m; j++) {
											                if (inp >= range[j][0] && inp <= range[j][1]) {
														                if (limit[j] < n) {
																	                    p[j][limit[j]] = inp;
																			                        limit[j]++;
																						                    i++;
																								                        check = 1;
																											                    break;
																													                    } else
																																                        printf("Range Full\n");
																															                }
													        }
										            if (check != 1)
												                printf("Invalid Age\n");
											        }
					        display(m, n, p);
}
