#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *myThread(void *vargp){
	printf("Thread id = %d\n",pthread_self());
	printf("Enter your name and age\n");
	char name[50];
	int age;
	//fgets(name,50,stdin);
	scanf("%[^\n]s",name);
	scanf("%d",&age);
	printf("Name = %s\nAge = %d\n",name,age);
}
int main(){
	pthread_t thread_id;
	pthread_create(&thread_id,NULL,myThread,NULL);
	pthread_exit(NULL);
	return 0;
}
