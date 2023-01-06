#include<stdio.h>
#include<dirent.h>
int main(){
	struct dirent *de;
	DIR *dr = opendir(".");
	if(dr == NULL){
		printf("Could not open the current directory\n");
		return 0;
	}
	printf("The current directory contents are\n");
	while( (de = readdir(dr)) != NULL){
		printf("%s\n",de->d_name);
	}
	rewinddir(dr);
	printf("\nPrinting the contents again\nThe current directory contents are\n");
	while( (de = readdir(dr)) != NULL){
		printf("%s\n",de->d_name);
	}

	closedir(dr);
	return 0;
}
