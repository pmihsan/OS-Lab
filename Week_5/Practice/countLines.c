#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

void main(){
	int size,count = 0;
	int fd = open("Hello.txt",O_RDONLY);
	char *c = (char *)calloc(100,sizeof(char));
	if(fd < 0){
		perror("Open Failure\n");
		return;
	}
	size = read(fd,c,100);
	c[size] = '\0';
	printf("The file contents are\n%s",c);
	for(int i=0;c[i] != '\0';i++){
		if(c[i] == '\n'){
			count++;
		}
	}
	printf("The number of lines is %d\n",count);
	close(fd);
}
