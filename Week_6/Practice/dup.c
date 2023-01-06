#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void main(){
	int fd;
	fd = open("sample.txt", O_WRONLY | O_APPEND);
	if(fd < 0){
		printf("File Open Failure\n");
		return;
	}
	int cp_fd = dup(fd);
	write(cp_fd, "Hello using copied fd", strlen("Hello using copied fd"));
	write(fd, "\nHello world", strlen("\nHello World"));
	close(fd);
}
