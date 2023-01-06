#include<stdio.h>
#include<pthread.h>

void *threadFunc(void *argp){
	int *a = (int *)argp;
	printf("The argument passed is %d\n",*a);
}

void main(){
	pthread_t tid;
	int a;
	printf("Enter an element\n");
	scanf("%d",&a);
	pthread_create(&tid,NULL,threadFunc,&a);
	pthread_exit(NULL);
}
