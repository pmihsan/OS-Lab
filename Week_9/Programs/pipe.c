#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

void main(){
	char buf[50];
	int p[2];
	int size;
	if(pipe(p) < 0) exit(1);
	if(fork() > 0){
		write(p[1],"Hello1",6);
		write(p[1],"Hello2",6);
		close(p[1]);
		wait(NULL);
	}
	else{
		close(p[1]);
		while( (size = read(p[0],buf,6)) > 0 ){
			printf("%s\n",buf);
		}
		if(size != 0) exit(2);
		printf("Finished Reading\n");
	}
}
