#include<stdio.h>
#include<unistd.h>

void main(int argc, char *argv[]){
	printf("PID of Hello = %d\n",getpid());
	printf("Hello world from hello.c\n");
	printf("Arguments from main process %s %s %s\n",argv[0],argv[1],argv[2]);
}
