#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
	fork();	
	fork();
	fork();
	printf("Hello World\n\n");
}
