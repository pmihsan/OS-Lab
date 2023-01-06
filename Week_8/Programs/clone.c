#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sched.h>

int func(void *arg){
	printf("This function called from child process\n");
	int *a = (int *)arg;
	printf("Argument passed = %d\n",*a);
	return 0;
}

void main(){
	printf("Parent process - %d\n",getpid());
	void *chStack = malloc(1024 * 1024);
	int x = 20;
	if(chStack == NULL) return;
	int pid = clone(func, chStack + (1024 * 1024),SIGCHLD,&x);
	if(pid < 0){
		printf("Unable to create child process\n");
		return;
	}
	wait(NULL);
	free(chStack);
	printf("End of the process\n");
}
