#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
void main(){
	int fd = open("sample.txt",O_RDWR);
	if(fd < 0){
		printf("File open failure\n");
		return;
	}
	int fd2 = dup(fd);
	write(fd,"Hello using fd\n",strlen("Hello using fd\n"));

	write(fd2,"Hello using fd2\n",strlen("Hello using fd2\n"));
	close(fd);
	close(fd2);
}
