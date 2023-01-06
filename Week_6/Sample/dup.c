#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

void main(){
	int fd = open("sample.txt", O_RDONLY);
	printf("After opening sample.txt using original fd => %d\n",fd);
	int cp_fd = dup(fd);
	printf("After taking a copy of fd using dup() we get fd => %d\n",cp_fd);
	close(fd);
	printf("After closing cp_fd => %d\n",cp_fd);
}
