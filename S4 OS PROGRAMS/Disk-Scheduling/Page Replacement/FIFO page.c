#include <stdio.h>
int main(){
	int i,j=0,k,pagefault=0,nf,np;
	int pages[20],frame[20];
	
	// Pages
	printf("Enter no of pages: ");
	scanf("%d",&np);
	printf("Enter the pages: ");
	for(i=0;i<np;i++){
		scanf("%d",&pages[i]);
	}
	
	// Frames
	printf("Enter no of frames: ");
	scanf("%d",&nf);
	for(i=0;i<nf;i++){
		frame[i] = -1;
	}
	
	printf("Ref String\tf1\tf2\tf3\n");
	for(i=0;i<np;i++){
		// printing ref strings
		printf("%d\t\t",pages[i]);
		
		for(k=0;k<nf;k++){
			// Condtn for Hit
			if(frame[k]==pages[i]){
				break;
			}
			// Condtn for Page Fault
			else{
				frame[j]=pages[i];
				j=(j+1)%nf;
				pagefault++;
				for(k=0;k<nf;k++){
					printf("%d\t",frame[k]);
				}
				printf("\n");
			}
		}
	}
	printf("Page Fault is %d",pagefault);
	return 0;
	
}