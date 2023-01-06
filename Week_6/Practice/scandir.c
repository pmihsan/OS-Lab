//#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main(){
	struct dirent **namelist;
	int n;
	n = scandir(".",&namelist,NULL,alphasort);
	if(n < 0){
		printf("Scan dir error\n");
		return 0;
	}
	while(n--){
		printf("%s\n",namelist[n]->d_name);
		free(namelist[n]);
	}
	free(namelist);
	return 0;
}
