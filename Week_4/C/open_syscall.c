#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
void main(){
	int fd = open("sample.txt", O_RDONLY);
	if(fd < 0){
		printf("fd = %d\n",fd);
		perror("Open Failure\n");
		return;
	}
	printf("fd = %d\n",fd);
	close(fd);
}
