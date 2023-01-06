#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

void main(){
	int a = fork();
	if(a == 0){ // running child process
		printf("Child Proces - %d\n",getpid());
	}
	else{ // created child running parent
		printf("Parent Process - %d\n",getpid());
		printf("So we will make the parent process wait\n");
		wait(NULL);	// parent waits for the child to complete the process
		printf("Now child process would be finished\n");
	}
	printf("Back to running process\n");
}
		
