#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

void main(){
	int fd;
	char *mypipe = "mypipe";
	mkfifo(mypipe,0666);
	char arr1[80],arr2[80];
	while(1){
		fd = open(mypipe,O_RDONLY);
		read(fd,arr1,sizeof(arr1));
		printf("Msg Read from Process 1 is: %s\n",arr1);
		close(fd);

		fd = open(mypipe,O_WRONLY);
		printf("Enter a message to send to process 1\n");
		fgets(arr2,80,stdin);
		write(fd,arr2,strlen(arr2)+1);
		close(fd);

	}
}
