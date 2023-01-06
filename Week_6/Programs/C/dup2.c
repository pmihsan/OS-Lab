#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main(){
	int fd = open("sample2.txt",O_WRONLY);
	if(fd < 0){
		printf("File open failure\n");
		return;
	}
	int fd2 = dup2(fd, 1);
	printf("Hello written using dup2 by forwarding stdout to fd\n");
	close(fd);
	//printf("%d\n",fd2);
	close(fd2);
}
