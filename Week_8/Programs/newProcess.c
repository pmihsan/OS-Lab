#include<stdio.h>
#include<unistd.h>
void main(int argc, char *argv[]){
	printf("Running  new processes => pid - %d\n",getpid());
	printf("Arguments is '%s'\n",argv[0]);
}
