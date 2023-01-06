#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX 2
#define BUFFER 2

sem_t empty;
sem_t full;

int in=0,out=0;
int buffer[BUFFER];

pthread_mutex_t mutex;

void *producer(void *pno){
	int item;
	for(int i=0;i<MAX;i++){
		item = rand();
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in] = item;
		printf("Producer %d: Inserted %d at %d\n", (*(int *)pno),buffer[in],in);
		in = (in + 1) % BUFFER;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}
}

void *consumer(void *cno){
	for(int i=0;i<MAX;i++){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item = buffer[out];
		printf("Consumer %d: Consumed %d from %d\n",(*(int *)cno),item,out);
		out = (out + 1)% BUFFER;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}
}
void main(){
	pthread_t pro[5],con[5];
	pthread_mutex_init(&mutex,NULL);
	sem_init(&empty,0,BUFFER);
	sem_init(&full,0,0);
	int a[2] = {1,2};
	for(int i=0;i<2;i++){
		pthread_create(&pro[i],NULL,(void *)producer,(void *)&a[i]);
	}
	for(int i=0;i<2;i++){
		pthread_create(&con[i],NULL,(void *)consumer,(void *)&a[i]);
	}
	for(int i=0;i<2;i++){
		pthread_join(pro[i],NULL);
	}
	for(int i=0;i<2;i++){
		pthread_join(con[i],NULL);
	}
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);
}
