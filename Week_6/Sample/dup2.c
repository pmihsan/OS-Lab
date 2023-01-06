#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
	int fd = open("sample.txt",O_WRONLY|O_APPEND);
	printf("After opening sample.txt fd => %d\n",fd);
	int cp_fd = dup2(fd, 1);
	printf("After using dup2() fd => %d and cp_fd => %d\n",fd,cp_fd);
}
