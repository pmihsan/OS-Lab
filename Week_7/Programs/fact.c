#include<stdio.h>
#include<pthread.h>

void *threadFunc(void *argp){
	int *a = (int *)argp;
	int fact = 1;
	if(*a < 0){
		fact = -1;
	}
	else if(*a == 0){
		fact = 1;
	}
	else{
		for(int i=1;i<=*a;i++){
			fact *= i;
		}
	}
	printf("Factorial of %d is %d\n",*a,fact);
}

void main(){
	pthread_t tid;
	int a;
	printf("Enter an number\n");
	scanf("%d",&a);
	pthread_create(&tid,NULL,threadFunc,&a);
	pthread_exit(NULL);
}
