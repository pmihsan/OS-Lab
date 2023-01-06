#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

void main(){
	DIR *dr = opendir(".");
	struct stat fi;
	struct dirent *de;
	creat("spotQ1.txt",S_IXUSR | S_IRUSR | S_IWUSR);
	int fd = open("spotQ1.txt",O_RDWR);
	if(dr == NULL){
		printf("Unable to open current directory\n");
		return ;
	}
	int fd2 = dup2(fd, 1);
	while( (de = readdir(dr)) != NULL){
	       lstat(de->d_name, &fi);
	       if( (fi.st_mode & S_IFMT) == S_IFREG){
		  if(strlen(de->d_name) > 3 && strstr(de->d_name, ".txt") != NULL && strcmp(de->d_name,"spotQ1.txt") != 0){
		  	  int fd1 = open(de->d_name,O_RDONLY);
			  char *c = (char *)calloc(100,sizeof(char));
			  if(fd1 < 0){
				  printf("File open error\n");
				  return;
			  }
			  int size = read(fd1,c,100);
			  c[size] = '\0';
			  printf("File - %s\n\n",de->d_name);
			  printf("%s\n",c);
			  close(fd1);
		  }
	       }
	}
	closedir(dr);
}

