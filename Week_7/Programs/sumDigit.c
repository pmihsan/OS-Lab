#include<stdio.h>
#include<pthread.h>

void *threadFunc(void *argp){
	int *a = (int *)argp;
	int sum = 0;
	int n = *a;
	if(*a == 0 || *a % 10 == *a){
		sum = *a;
	}
	else{
		while(*a > 0){
			int rem = *a % 10;
			sum += rem;
			*a = *a / 10;
		}
	}
	printf("Sum of digits in %d is %d\n",n,sum);
}

void main(){
	pthread_t tid;
	int a;
	printf("Enter an number\n");
	scanf("%d",&a);
	pthread_create(&tid,NULL,threadFunc,&a);
	pthread_exit(NULL);
}
