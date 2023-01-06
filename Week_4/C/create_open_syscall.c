#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
void main(){
	int fd = open("cre_op.txt",O_CREAT,O_EXCL,S_IRWXU);
	if(fd < 0){
		printf("Open failure\n");
		perror("OPF");
		return;
	}
	printf("fd = %d\n",fd);
	//close(fd);
	int fd1 = open("cre_op.txt",O_WRONLY);
	printf("fd1 = %d\n",fd1);
	int size = write(fd1, "Hello to create open file\n", strlen("Hello to create open file\n"));
	close(fd);
	close(fd1);
}
