#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void main(){
	key_t key = ftok("SharedMemoryFile",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	char *str = (char *)shmat(shmid,(void*)0,0); 
	printf("Enter the data to write in memory\n");
	gets(str);
	printf("Data written in the memory is %s\n",str);
	shmdt(str);
	//shmctl(shmid,IPC_RMID,NULL);
}