#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int pid1, pid2;
	printf("Parent process id - %d\n",getppid());
	int pid = fork();
	printf("pid = %d\n",pid);
	if(pid == 0){
		sleep(3);
		printf("Child 1 created pid = %d\n",getpid());
	}
	else{
		pid1 = fork();
		printf("pid1 = %d\n",pid1);
		if(pid1 == 0){
			sleep(2);
			printf("Child 2 created pid = %d\n",getpid());
		}
		else{
			pid2 = fork();
			printf("pid2 = %d\n",pid2);
			if(pid2 == 0){
				printf("Child 3 created pid = %d\n",getpid());
			}
			else{
				sleep(3);
				printf("Parent Process - %d\n",getppid());
			}
		}
	}
	return 0;
}
