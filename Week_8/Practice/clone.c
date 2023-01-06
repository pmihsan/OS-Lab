#include<stdio.h>
#include<unistd.h>
#include<sched.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

void func(void *argv){
	printf("Function is called from child process\n");
}

void main(){
	printf("Parent Process %d\n",getpid());
	void *childStack = malloc(1024 * 1024);
	if( childStack == NULL){
		exit(1);
	}
	int pid = clone(func, childStack+(1024 * 1024), SIGCHLD, NULL);
	if(pid < 0){
		printf("Unable to create child process\n");
		exit(1);	
	}
	wait(NULL);
	free(childStack);
	printf("End of the process\n");
}
