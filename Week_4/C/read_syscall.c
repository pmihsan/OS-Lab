#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void main(){
	int fd = open("sample.txt", O_RDONLY);
	char *str = (char*)calloc(100, sizeof(char));
	if(fd < 0){
		perror("Open Failure\n");
		return;
	}
	printf("fd - %d\n",fd);
	int size = read(fd, str,100);
	str[size] = '\0';
	printf("File contents - %s",str);
	close(fd);
}
