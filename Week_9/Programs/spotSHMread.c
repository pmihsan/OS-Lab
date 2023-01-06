#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
void main(){
	key_t key = ftok("SpotSHM",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	char *str = (char *)shmat(shmid,(void*)0,0); 
	printf("Data read from the memory is ");
	for(int i=0;i<strlen(str);i++){
		if(str[i] >= 97 && str[i] <= 122) str[i] = str[i] - 32;
	}
	printf("%s\n",str);
	shmdt(str);
	shmctl(shmid,IPC_RMID,NULL);
}
