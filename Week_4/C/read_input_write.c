#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void main(){
	char buffer[50];
	char buf[50];
	char filename[20];
	
	printf("Enter Filename\n");
	scanf("%s",filename);
	getchar();
	
	int fd = open(filename, O_CREAT,S_IRWXU);
        if(fd < 0){
		printf("Create Open file failure\n");
		perror("COPF: ");
		return ;
	}
	printf("\nfd = %d\nFile created successfully\n",fd);	
	close(fd);

	printf("\nEnter a string(max 45 characters) to write in the file %s\n",filename);
	fgets(buffer,50,stdin);
	buffer[strlen(buffer) - 1] = '\0';
	fd = open(filename, O_WRONLY);
        if(fd < 0){
		printf("Write Open file failure\n");
		perror("WOPF: ");
		return ;
	}	
	printf("\nfd = %d\nFile opened for writing\n",fd);
	int size = write(fd, buffer, strlen(buffer));
	printf("Write operation successful\n");
	close(fd);

	fd = open(filename, O_RDONLY);
	printf("\nfd = %d\nFile opened for reading\n",fd);
	int sz = read(fd,buf,strlen(buffer)); 
	printf("Read operation Successful\n\nFile contains - %s\n",buf);
	close(fd);
}
