#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

void main(){
	struct dirent **namelist;
	int n = scandir(".", &namelist,NULL,alphasort);
	if(n < 0){
		printf("Scandir error\n");
		return;
	}
	for(int i=0;i<n;i++){
		printf("%s\n",namelist[i]->d_name);
		free(namelist[i]);
	}
	free(namelist);
}
