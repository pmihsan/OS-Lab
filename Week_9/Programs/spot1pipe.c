#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

void main(){
	char *str = (char *)calloc(50,sizeof(char));
	int p[2];
	int size;
	if(pipe(p) < 0) exit(1);
	if(fork() > 0){
		char arr[50];
		printf("Enter a string in lower case\n");
		fgets(arr,50,stdin);
		write(p[1],arr,50);
		close(p[1]);
		wait(NULL);
	}
	else{
		close(p[1]);
		size = read(p[0],str,50);
		str[size] = '\0';
		for(int i=0;str[i] != '\n';i++){
			
			if(str[i] >= 97 && str[i] <= 122) printf("%c",str[i]-32);
			else printf("%c",str[i]);
		}
		printf("\n");
		if(size != 0) exit(2);
		printf("Finished Reading\n");
	}
}
