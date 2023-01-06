#include<stdio.h>
void main(int argc, char *argv[]){
	printf("%d\n",argc);

	if(argc == 1){
		printf("No arguments...\n");
		return;
	}
	printf("Printing arguments\n");
	for(int i =1;i<argc;i++){
		printf("%s\n",argv[i]);
	}
}
