#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

void main(){
	int n;
	int size,age,id = 0;
	char emp_name[40];
	int fd = open("employer.txt",O_RDWR);
	char *c = (char *)calloc(100,sizeof(char));
	if(fd < 0){
		perror("Open Failure\n");
		return;
	}
	size = write(fd, "EMP_NAME EMP_AGE EMP_ID\n", strlen("EMP_NAME EMP_AGE EMP_ID\n"));
	printf("Enter number of employees\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char buffer[40];
		printf("Employer - %d\n",i+1);
		printf("Enter a employer name\n");
		scanf("%s",&emp_name);
		printf("Enter employer age\n");
		scanf("%d",&age);
		printf("Enter employer id\n");
		scanf("%d",&id);
		snprintf(buffer, 40, "%s\t%d\t%d\n",emp_name,age,id);	
		size = write(fd, buffer, strlen(buffer));
	}
	close(fd);
	fd = open("employer.txt",O_RDONLY);
	if(fd < 0){
		perror("Open Failure");
		return;
	}
	char *s = (char *)calloc(100,sizeof(char));
	size = read(fd, s, 100);
	s[size] = '\0';
	//printf("After adding details the file contents are\n");
	//printf("EMP_NAME EMP_AGE EMP_ID\n%s",s);
	printf("%s",s);
	close(fd);
}
