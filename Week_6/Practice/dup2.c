#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main(){
	int fd = open("sample2.txt", O_WRONLY | O_APPEND);
	if(fd < 0){
		printf("File Open Failure\n");
		return;
	}
	dup2(fd,1);
	printf("This is written to sample2.txt\nHello World\n");
}
