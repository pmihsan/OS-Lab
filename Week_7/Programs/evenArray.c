#include<stdio.h>
#include<pthread.h>

void *threadFunc(void *argp){
	int *a = (int *)argp;
	printf("Even Number\n");
	for(int i=0;i<5;i++){
		if(a[i] %2 == 0){
			printf("%d\n",a[i]);
		}
	}
}

void main(){
	pthread_t tid;
	int arr[5] = {1,4,5,66,12};
	pthread_create(&tid,NULL,threadFunc,arr);
	pthread_exit(NULL);
}
