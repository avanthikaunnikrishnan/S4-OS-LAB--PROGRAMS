#include <stdio.h>

int main(){
	int quant,n,i,rnop,time=0;
	float avg_wt = 0,avg_tat = 0;
	float total_tat = 0,total_wt = 0;
	
	
	printf("Enter no of process: ");
	scanf("%d",&n);
	rnop = n;
	
	int bt[n],wt[n],tat[n],p[n],rbt[n];
	
	printf("Enter time quantum: ");
	scanf("%d",&quant);
	
	for(i = 0; i < n; i++){
        p[i]=i+1;
        printf("Burst Time for Process  %d: ", p[i]);
        scanf("%d",&bt[i]);
        rbt[i] = bt[i];
    }
    
    for(i=0 ; rnop!=0 ; i = (i+1)%n){
		if(rbt[i]<=quant && rbt[i]>0){
			time += rbt[i];
			rbt[i] = 0;
			rnop--;
			tat[i] = time;
			wt[i] = tat[i] - bt[i];
			total_tat += tat[i];
			total_wt += wt[i];
		}
		else if(rbt[i]>quant){
			rbt[i] -= quant;
			time += quant;
		}
		
	avg_tat = (float)total_tat/(float)n;
	avg_wt = (float)total_wt/(float)n;
	}
	
	printf("P   BT  TAT  WT\n");
    for (int i = 0; i < n; i++){
        printf("%d   %d   %d   %d\n", p[i], bt[i], tat[i], wt[i]);
    }
    printf("Average Waiting Time: %f\n", avg_wt);
    printf("Average Turn Around Time: %f\n", avg_tat);
}