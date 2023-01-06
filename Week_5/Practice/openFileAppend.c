#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void main(){
	int fd = open("sample3.txt",O_RDWR);
	if(fd < 0){
		printf("Open Failure\n");
		return;
	}
	char *str = (char *)calloc(100,sizeof(char));
	int size = read(fd,str,100);
	str[size] = '\0';
	char buffer[40];
	printf("The file contents are\n%s",str);
	printf("\nEnter a string to append\n");
	fgets(buffer,40,stdin);
	size = write(fd, buffer, strlen(buffer));
	close(fd);
	fd = open("sample3.txt", O_RDONLY);
	printf("\nAfter Appending the file contents are\n");
	char *s = (char *)calloc(100,sizeof(char));
	size = read(fd,s,100);
	s[size] = '\0';
	printf("%s",s);
	close(fd);
}
