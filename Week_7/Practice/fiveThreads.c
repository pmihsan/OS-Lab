#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *myThread(void *vargp){
	printf("Hi\n");
	pthread_exit(NULL);
}
void main(){
	pthread_t thread_id;
	for(int i=0;i<5;i++){
		pthread_create(&thread_id,NULL,myThread,NULL);
		pthread_join(thread_id,NULL);
	}
}
