#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>

void main(){
	struct dirent *de;
	struct stat fi;
	DIR *dr = opendir(".");
	if(dr == NULL){
		printf("Unable to open the specified directory\n");
		return;
	}
	printf("The files in the current directory are\n");
	while((de = readdir(dr)) != NULL){
		lstat(de->d_name,&fi);
		if((fi.st_mode & S_IFMT) == S_IFREG){
			printf("\n%s\nFile Mode - %d\n",de->d_name,fi.st_mode);
		}
	}
	closedir(dr);
}
