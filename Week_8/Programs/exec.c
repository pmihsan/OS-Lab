#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main(){
	printf("Main Process running - %d\n",getpid());
	char *argv[] = {"From Program execv", NULL};
	execv("./newProcess",argv);
	printf("Back to main processes\n");
}
