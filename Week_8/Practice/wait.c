#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

void main(){
	if(fork() == 0){
		printf("In child Process %d\n",getpid());
	}
	else{
		printf("Parent Process %d waits...\n",getpid());
		wait(NULL);		
		printf("After the end of child process => Parent continues\n");
	}
	printf("Back to end of the processes\n");
}
