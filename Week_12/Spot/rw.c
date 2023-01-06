#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

sem_t wrt ; 
pthread_mutex_t mutex ; 
int cnt =1 ; 
int numreader = 0 ; 

void * writer(void *wno)	{
	sem_wait(&wrt) ; 
	cnt = cnt*2 ; 
	printf("Writer %d modified cnt to %d\n",(*((int*)wno)),cnt) ; 
	sem_post(&wrt) ;
}
void * reader(void* rno)	{
	pthread_mutex_lock(&mutex) ; 
	numreader++ ; 
	if(numreader == 1)	{
       		sem_wait(&wrt) ; 		
	}
	pthread_mutex_unlock(&mutex) ; 
	printf("Reader %d : read cnt as %d\n",*((int*)rno),cnt) ; 
	pthread_mutex_lock(&mutex) ; 
	numreader-- ; 
	if(numreader == 0)	{
		sem_post(&wrt) ; 
	}
	pthread_mutex_unlock(&mutex) ; 
} ; 
int main()	{
	pthread_t read[10], write[5] ; 
	pthread_mutex_init(&mutex,NULL) ; 
	sem_init(&wrt,0,1) ; 
	int a[10] = {1,2,3,4,5,6,7,8,9,10} ; 
	int r,w ; 
	printf("Enter the number of reader process : ") ; 
	scanf("%d" , &r) ; 
	printf("Enter the number of writer process : ") ; 
	scanf("%d", &w) ; 
	int rP[r] , wP[w] ; 
	printf("Enter the priorities of %d reader process : ",r) ; 
	for(int i = 0 ; i < r ; i++)	{
		scanf("%d" , &rP[i]) ; 
	}
	printf("Enter the priorities of %d writer process : " ,w) ; 
	for(int i = 0 ; i < w; i++)	{
		scanf("%d", &wP[i]) ; 
	}
	int k =0 , j = 0 , l = 0, i;
	while(l < r+w)	{
		printf("%d and %d\n" , wP[k], rP[j]) ; 
		if(wP[k] <= rP[j])	{
			//execute one write process
			k++ ; 
			l++ ; 
			printf("WRITER\n") ;
			pthread_create(&write[(k-1)],NULL,(void*)writer,(void*)&a[k-1]) ; 
			pthread_join(write[k-1],NULL) ;
			for(i = 0 ; i < r ; i++)	{
				rP[i]-- ; 
			}	
		}
		else	{
			for(i = 0 ; i < r; i++)	{
				l++ ; 
			 	
				pthread_create(&read[i],NULL,(void*)reader,(void*)&a[i]) ; 
			}
			for(i = 0 ; i < r ; i++)	{
				pthread_join(read[i],NULL) ; 
			}
			for(i = 0; i < r ; i++)	{
				rP[i] = 10000 ; 
			}
			printf("READER\n") ; 
		}
	}

	
	/*for(int i = 0 ; i < 10 ; i++)	{
		pthread_create(&read[i],NULL, (void*)reader,(void*)&a[i]) ; 
	}
	for(int i=0 ; i < 5 ; i++)	{
		pthread_create(&write[i],NULL,(void*)writer,(void*)&a[i]) ; 
	}
	for(int i = 0 ; i < 10 ; i++)	{
		pthread_join(read[i],NULL) ; 
	}
	for(int i = 0 ; i < 5 ; i++)	{
		pthread_join(write[i],NULL) ; 
	}
	for(int i = 0 ; i < 10; i++)	{
		printf("%d ", a[i]) ; 
	}*/
	pthread_mutex_destroy(&mutex) ; 
	sem_destroy(&wrt) ; 
	return 0 ; 
}

