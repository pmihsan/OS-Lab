#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
void main(int argc, char *argv[]){
	if(argc == 1){
		printf("No file name in the argument\n");
		return;
	}
	int fd = open(argv[1], O_RDWR);
	if(fd < 0){
		printf("Open Failure\nEnter a valid filename\n");
		perror("OP - ");
		return;
	}
	char *str = (char *)calloc(100, sizeof(char));
	int sz = read(fd, str, 100);
	str[sz] = '\0';
	printf("In '%s' the file contents are\n%s",argv[1],str);
	printf("\n");
	char buffer[40];
	printf("Enter a string\n");
	fgets(buffer, 40, stdin);	
	int size = write(fd, buffer, strlen(buffer));
	close(fd);
}

