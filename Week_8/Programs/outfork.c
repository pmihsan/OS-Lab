#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
	fork();
	for(int i=0;i<2;i++){
		printf("Hello World %d\n",i);
	}
	printf("After for loop\n");
}
