#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
	int pid,status;
	char *args[]={"ls","-l",0};
	printf("Parent process\n");
	pid = fork();
	if(pid==0){
		printf("Child process\n");
		execv("/bin/ls",args);
	}
	else{
		wait(&status);
		printf("Parent Process\n");
		exit(0);
	}
}