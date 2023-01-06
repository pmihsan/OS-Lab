#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define size 16

char *str = "Hello, World #1";

int main(){
	char buf[size];
	int p[2];
	int i;
	
	if(pipe(p) < 0){
		exit(1);
	}
	write(p[1],str,size);
	read(p[0],buf,size);
	printf("Read Result - %s\n",buf);
	return 0;
}
