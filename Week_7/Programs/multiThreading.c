#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *thread(void * argp){
	printf("Thread id = %d\n",pthread_self());		
	//pthread_exit(NULL);
}
void main(){
	pthread_t tid;
	for(int i=0;i<4;i++){
		pthread_create(&tid,NULL,thread,NULL);
	//	pthread_join(tid,NULL);
	}
	pthread_exit(NULL);
}
