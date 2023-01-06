#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *myThread(void *vargp){
	int *x = (int *)vargp;
	printf("Argument passed = %d\n",*x);
}
int main(){
	pthread_t thread_id;
	int x;
	printf("Enter a value to pass as an argumnet\n");
	scanf("%d",&x);
	pthread_create(&thread_id,NULL,myThread,&x);
	pthread_join(thread_id,NULL);
	pthread_exit(NULL);
	return 0;
}
