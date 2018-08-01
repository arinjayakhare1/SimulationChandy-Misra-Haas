#include<bits/stdc++.h>

int n;
int **a;
int flag = 0;
void probe(int init,int k)
{
	for(int i = 0;i < n;i++)
	{
		if(a[k][i] == 1)
		{
			if(i == init)
			{
				printf("S%d -> S%d\t(%d,%d,%d)-------->Deadlock Detected\n",k + 1,i + 1,init + 1,k + 1,i + 1);
				flag = 1;break;
			}
			printf("S%d --> S%d\t(%d,%d,%d)\n",k + 1,i + 1,init + 1,k + 1,i + 1);
			probe(init,i);
		}
	}
}


void ChandyMishraHass(int init)
{
	printf("\n\nProvisional setup for checking deadlock\n");
	printf("____________________________________________________________\n\n");
	printf(" CHANDY-MISRA-HAAS DISTRIBUTED DEADLOCK DETECTION ALGORITHM\n\n");
	for(int i = 0;i < n;i++)
	{
		printf("\tS%d",i + 1);
	}
	printf("\n");
	for(int i = 0;i < n;i++)
	{
		printf("S%d",i + 1);
		for(int j = 0;j < n;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}


	int p = init - 1;
	printf("\n\nDirection\tProbe\n");
	for(int j = 0;j < n;j++)
	{
		if(a[p][j] == 1)
		{
			printf("S%d --> S%d\t(%d,%d,%d)\n",p + 1,j + 1,init,p + 1,j + 1);
			probe(p,j);
		}
	}
	if(flag == 0)
	{
		printf("\n\nNo Deadlocks detected\n");
	}
	printf("____________________________________________________________");
}


int main()
{
	printf("Enter number of processes:\n");
	scanf("%d",&n);
	a = (int **)malloc(n * sizeof(int *));
	for(int i = 0;i < n;i++)
	{
		a[i] = (int *)malloc(n * sizeof(int));
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			a[i][j] = 0;
		}
	}

	printf("\nThe current dependency array is:-\n");
	//printf("____________________________________________________________\n\n");
	//printf(" CHANDY-MISRA-HAAS DISTRIBUTED DEADLOCK DETECTION ALGORITHM\n\n");
	for(int i = 0;i < n;i++)
	{
		printf("\tS%d",i + 1);
	}
	printf("\n");
	for(int i = 0;i < n;i++)
	{
		printf("S%d",i + 1);
		for(int j = 0;j < n;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}

	while(1)
	{
		int init;
		printf("\n\nEnter initiator process or -1 to exit:\n");
		scanf("%d",&init);
		if(init == -1)
		{
			break;
		}
		else
		{
			int dest;
			printf("\n\nEnter process to be requested for resource:\n");
			scanf("%d",&dest);
			if(dest == init)
			{
				printf("\n\nInititiaor and requested processes same. Retry\n");
			}
			else if(a[init - 1][dest - 1] == 1)
			{
				printf("\n\nInitiator already requesting resources from the entered process.Deallocating the resource.\n");
				a[init - 1][dest - 1] = 0;
			}
			else
			{
				a[init - 1][dest - 1] = 1;
				printf("\n\nChecking if this request will result in deadlock\n\n");
				ChandyMishraHass(init);
				if(flag)
				{
					printf("\n\nThis request will result in deadlock so this request will not be fulfilled\n");
					a[init - 1][dest - 1] = 0;
					flag = 0;
				}
				printf("\n\nThe current dependency array is:-\n");
				//printf("____________________________________________________________\n\n");
				//printf(" CHANDY-MISRA-HAAS DISTRIBUTED DEADLOCK DETECTION ALGORITHM\n\n");
				for(int i = 0;i < n;i++)
				{

					printf("\tS%d",i + 1);
				}
				printf("\n");
				for(int i = 0;i < n;i++)
				{
					printf("S%d",i + 1);
					for(int j = 0;j < n;j++)
					{
						printf("\t%d",a[i][j]);
					}
					printf("\n");
				}
			}
		}
	}
}