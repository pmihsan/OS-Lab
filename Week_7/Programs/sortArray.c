#include<stdio.h>
#include<pthread.h>


void printArray(int arr[], int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void *threadFunc(void *argp){
	int *arr = (int *)argp;
	int n = 5;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[j] < arr[i]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}	
		printArray(arr,n);
	}
}

void main(){
	pthread_t tid;
	int arr[5] = {7,5,3,9,1};
	pthread_create(&tid,NULL,threadFunc,arr);
	pthread_exit(NULL);
}
