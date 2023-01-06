#include<stdio.h>
#include<pthread.h>
void *myThread(void *vargp){
	int *a = (int *)vargp;
	int ans = 0;
	for(int i=0;i<5;i++){
		ans += a[i];
	}
	printf("Sum = %d\n",ans);
}
int main(){
	pthread_t thread_id;
	int arr[5] = {10,20,34,11,22};
	pthread_create(&thread_id,NULL,myThread,arr);
	pthread_exit(NULL);
	return 0;
}
