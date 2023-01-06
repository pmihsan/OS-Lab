#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void main(){
	for(int i=0;i<2;i++){
		fork();
		printf("Hello World\n");
	}
	printf("After for loop\n");
}
