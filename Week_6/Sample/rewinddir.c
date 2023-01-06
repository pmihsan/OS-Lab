#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
void main(){
	DIR *dr = opendir(".");
	if(dr == NULL){
		exit(1);
	}
	struct dirent *ds;
	while((ds = readdir(dr)) != NULL){
		printf("%s -> ",ds->d_name);
	}
	rewinddir(dr);
	ds = readdir(dr);
	printf("\nAfter rewinding ds points to %s\n",ds->d_name);
	closedir(dr);
}

