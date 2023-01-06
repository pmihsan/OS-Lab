#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main(){
	
	fork();
	for(int i=0;i<2;i++){
		printf("Hello World\t");
	}
	printf("\n");
}
