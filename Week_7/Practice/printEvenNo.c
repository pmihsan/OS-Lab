#include<stdio.h>
#include<pthread.h>
void *myThread(void *vargp){
	int *a = (int *)vargp;
	printf("Even Numbers\n");
	for(int i=0;i<5;i++){
		if(a[i] % 2 == 0){
			printf("%d\n",a[i]);
		}
	}
}
int main(){
	pthread_t thread_id;
	int arr[5] = {10,21,34,11,22};
	pthread_create(&thread_id,NULL,myThread,arr);
	pthread_exit(NULL);
	return 0;
}
