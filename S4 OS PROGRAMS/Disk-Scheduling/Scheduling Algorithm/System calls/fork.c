#include <stdio.h>
#include <unistd.h>

int main(){
	int value = fork();
	printf("PID: %d\n",value);
}
