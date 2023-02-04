#include <stdio.h>

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int n,i,j;
	float avg_wt = 0,avg_tat = 0;
	float total_tat = 0,total_wt = 0;
	
	printf("Enter no of process: ");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n],p[n],pr[n];
	
	for (int i = 0; i < n; i++){
        p[i]=i+1;
        printf("Burst Time && Priority of Process  %d: ", p[i]);
        scanf("%d",&bt[i]);
        scanf("%d",&pr[i]);
    }
    
    for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(pr[j]>pr[j+1]){
				// swapping process_no, priority and burst_time
				swap(&pr[j],&pr[j+1]);
				swap(&p[j],&p[j+1]);
				swap(&bt[j],&bt[j+1]);
			}
		}
	}
	
	for(i=0;i<n;i++){
		if(i==0){
			tat[i] = bt[i];
		}
		else{
			tat[i] = tat[i-1] + bt[i];
		}
		wt[i] = tat[i] - bt[i];
		total_tat += tat[i];
		total_wt += wt[i];
	}
	
	avg_tat = (float)total_tat/(float)n;
	avg_wt = (float)total_wt/(float)n;
	
	printf("P   BT  WT  TAT\n");
    for (int i = 0; i < n; i++){
        printf("%d   %d   %d   %d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("Average Waiting Time: %f\n", avg_wt);
    printf("Average Turn Around Time: %f\n", avg_tat);


}	