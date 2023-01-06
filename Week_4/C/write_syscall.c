#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
	int fd = open("sample.txt",O_WRONLY);
	char str[] = "Hello using write syscall\n";
	if(fd < 0){
		perror("Open failure\n");
		return;
	}
	printf("fd = %d\n",fd);
	int size = write(fd, str, strlen(str));
	close(fd);
}
