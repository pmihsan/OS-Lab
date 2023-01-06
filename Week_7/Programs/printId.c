#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *myThread(void *argp){
	char name[50];
	int age;
	printf("Thread id = %d\n",pthread_self());
	printf("Enter a name and age\n");
	fgets(name,50,stdin);
	scanf("%d",&age);
	printf("Name  = %sAge = %d\n",name,age);

}
void main(){
	pthread_t thread_id;
	pthread_create(&thread_id,NULL,myThread,NULL);
	pthread_exit(NULL);
}
