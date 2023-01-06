#include<stdio.h>
#include<sys/unistd.h>
#include<sys/types.h>
void main(){
	fork();
	fork();
	printf("Process id - %d\n",getpid());
}
