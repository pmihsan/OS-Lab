#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
void main(){
	DIR *dr = opendir(".");
	if(dr == NULL){
		printf("Could not open the current dirctory\n");
		return;
	}
	struct stat fi;
	struct dirent *de;
	char str[50];
	system("mkdir C");
	system("mkdir Text");
	system("mkdir Other");
	while( (de = readdir(dr)) != NULL ){
			lstat(de->d_name,&fi);
			strcpy(str, "mv ");
			strcat(str, de->d_name);
			if((fi.st_mode & S_IFMT) == S_IFREG){
				if(strlen(de->d_name) > 3 && strstr(de->d_name,".txt") != NULL){
					strcat(str, " ./Text");
					printf("%s\n",str);
					system(str);
					strcpy(str, "");
				}
				if(strlen(de->d_name) > 2 && strstr(de->d_name,".c") != NULL){
					strcat(str, " ./C");
					printf("%s\n",str);
					system(str);
					strcpy(str, "");
				}
				else{
					strcat(str, " ./Other");
					printf("%s\n",str);
					system(str);
					strcpy(str, "");
				}
			}/*
			else if((fi.st_mode & S_IFMT) != S_IFDIR){
					strcat(str, " ./Other");
					printf("%s\n",str);
					system(str);
					strcpy(str, "");
			}*/

	}
	closedir(dr);

}

