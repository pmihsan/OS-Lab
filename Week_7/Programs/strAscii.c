#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

void *myThread(void *argp){
	char *s = (char *)argp;
	printf("Ascii value of given string - %s",s);
	for(int i=0;s[i] != '\n';i++){
		printf("%d ",s[i]);
	}
	printf("\n");
}

void main(){
	pthread_t tid;
	char str[50];
	printf("Enter a string\n");
	fgets(str,50,stdin);
	//printf("%s",str);
	//str[strlen(str)] = '\0';	
	pthread_create(&tid,NULL,myThread,str);
	pthread_exit(NULL);
}
