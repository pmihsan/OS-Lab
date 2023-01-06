#include<stdio.h>
#include<pthread.h>

void *threadFunc(void *argp){
	int *a = (int *)argp;
	int ans = 0;
	//int n = sizeof(a)/sizeof(a[0]);
	for(int i=0;i<5;i++){
		ans += a[i];
	}
	printf("Sum of the array is %d => n is %d\n",ans,n);
}

void main(){
	pthread_t tid;
	int arr[5] = {1,3,5,7,9};
	pthread_create(&tid,NULL,threadFunc,arr);
	pthread_exit(NULL);
}
