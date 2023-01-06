#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#define size 16

char *str = "Hello, World #1";
char *str1 = "Hello, World #2";
char *str2 = "Hello, World #3";

int main(){
	char buf[size];
	int p[2];
	int sze;
	
	if(pipe(p) < 0){
		exit(1);
	}
	if(fork() > 0){
		write(p[1],str,size);
		write(p[1],str1,size);
		write(p[1],str2,size);
		close(p[1]);
		wait(NULL);
	}
	else{
		close(p[1]);
		while((sze = read(p[0],buf,size)) > 0){
			printf("%s\n",buf);
		}
		if(sze != 0){
			exit(2);
		}
	printf("Finished Reading\n");
	}
	return 0;
}
