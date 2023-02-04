#include <stdio.h>
int main()
{
	int p,r,i,j,k,flag,count=0;
	printf("\nenter the no. of processses : ");
	scanf("%d",&p);
	printf("\nenter the number of resources :");
	scanf("%d",&r);
	int alloc[p][r],max[p][r],need[p][r];
	int avail[r],finish[p],safe[p];
	
	printf("\nEnter the allocation:\n");
	for(i=0;i<p;i++)
	{
		printf("process P%d\n",i);
		for(j=0;j<r;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("Enter the max resources:\n");
	for(i=0;i<p;i++)
	{
		printf("Process p%d:\n",i);
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("\nNeed matrix:\n");
	for(i=0;i<p;i++)
	{
		printf("Process p%d:\n",i);
		for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
			printf("%d\t",need[i][j]);
		}
		printf("\n");
	}
	printf("Enter available resources:\n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
	}
	
	
	for(i=0;i<p;i++)
		finish[i]=0;
	
	for(k=0;k<p;k++)
	{
		for(i=0;i<p;i++)
		{
			if(finish[i]==0)
			{
				for(j=0;j<r;j++)
				{
					if(need[i][j]<=avail[j])
						flag=1;
					else
					{
						flag=0;
						break;
					}
				}
				if(flag==1)
				{
					safe[count]=i;
					for(j=0;j<r;j++)
						avail[j]+=alloc[i][j];
					finish[i]=1;
					count++;
				}
			}
		}
	}
	
	for(i=0;i<p;i++)
	{
		if(finish[i]==0)
		{
			printf("\nthe system is not safe state\n");	
			return 0;
		}
	}
	printf("the safe sequence is : \n");
	for(i=0;i<p;i++)
		printf("p%d\t",safe[i]);
		
	printf("\nthe system is in safe state\n");
}