#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
void main(int argc, char *argv[]){
	if(argc == 1){
		printf("No file name in the argument\n");
		return;
	}
	if(argc == 2){
		printf("Enter two filenames (one missing)\n");
		return;
	}
	creat(argv[2], S_IWUSR | S_IRUSR);
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		printf("Open Failure\nEnter a valid source filename\n");
		perror("OP - ");
		return;
	}
	char *str = (char *)calloc(100, sizeof(char));
	int sz = read(fd, str, 100);
	str[sz] = '\0';
	//printf("In source file '%s' the contents are\n%s",argv[1],str);
	close(fd);
	int fd1 = open(argv[2], O_WRONLY);
	if(fd1 < 0){
		printf("Open Failure\n");
		perror("Write file failed: ");
		return;
	}
	int size = write(fd1,str,strlen(str));
        close(fd1);	
}

