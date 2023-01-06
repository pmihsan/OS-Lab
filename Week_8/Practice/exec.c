#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(){
	printf("PID of example is %d\n",getpid());
	printf("From Example.c\n");
	char *args[] = {"Hello", "C", "Execv Syscall",NULL};
	execv("./hello",args);
	printf("Back to example.c file\n");
}
