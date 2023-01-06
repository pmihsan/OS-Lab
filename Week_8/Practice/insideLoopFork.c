#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

void main(){
	for(int i=0;i<2;i++){
		fork();
		printf("\n");
	}
	printf("Hello World\n");
}
