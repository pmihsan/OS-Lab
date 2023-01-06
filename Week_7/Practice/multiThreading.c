#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *myThread(void *vargp){
	printf("Thread id = %d\n",pthread_self());
}
int main(){
	pthread_t thread_id;
	printf("MultiThreading\n");
	for(int i=0;i<4;i++){
		pthread_create(&thread_id,NULL,myThread,NULL);
	}
	pthread_exit(NULL);
	return 0;
}
