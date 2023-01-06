#include<stdio.h>
#include<pthread.h>

void *myThrd(void * argp){	
//	printf("%d\n",pthread_self());
	printf("Hello World!..\n");
	pthread_exit(NULL);
}
void main(){	
	pthread_t tid;
	printf("Main Thread Id: %d\n",tid);
	for(int i=0;i<5;i++){
		pthread_create(&tid,NULL,myThrd,NULL);
		pthread_join(tid,NULL);
	}
}
