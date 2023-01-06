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
	while(size = read(fd,c,100) > 0){
//		for(int i=0;i<size;i++){
//			if(c[i] == '\n'){
				count++;
//			}
//		}
	}
	printf("The number of lines in 'Hello.txt' is %d\n",count);
	close(fd);
}
