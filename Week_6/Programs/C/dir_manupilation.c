#include<stdio.h>
#include<dirent.h>
void main(){
	struct dirent *dir;
	DIR *dr = opendir(".");
	if(dr == NULL){
		printf("Unable to open the specified directory\n");
		return;
	}
	while((dir = readdir(dr)) != NULL){
		printf("%s\n",dir->d_name);
	}
	closedir(dr);
}
