#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

struct dirent *dptr;
int main(){
	char buff[200];
	DIR *dirp;
	printf("Enter directory name: ");
	scanf("%s",buff);
	if((dirp=opendir(buff))==NULL){
		printf("Error");
		exit(0);
	}
	while(dptr=readdir(dirp)){
        printf("%s\n",dptr->d_name);
    }
	closedir(dirp);
}