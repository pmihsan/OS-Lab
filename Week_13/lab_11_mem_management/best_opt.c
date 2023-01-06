#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define max 10
void optimize(int [],int,int [],int,int []);
void allocateMem(int processSize[],int m,int memBlock[],int n){
	int flag[max];
	int i;
	bool flagprogress=false;
	for(i=0;i<m;i++){
		flag[i]=0;
	}

	for (int i = 0; i < m; i++){
		int minIndex = -1;
		int minVal = INT_MAX;
		for (int j = 0; j < n; j++){
			if (processSize[i] <= memBlock[j] && memBlock[j] < minVal ){
				minIndex = j;
				minVal = memBlock[j];
			}
		}
		if (minIndex != -1){
			flag[i]=1;
			printf("Allocated Process %d[%d] at %d[%d] block\n",i,processSize[i],minIndex + 1,memBlock[minIndex]);
			memBlock[minIndex] -= processSize[i];
			processSize[i]=-1;
		}
		else{	
			flag[i]=0;
			flagprogress=true;
			printf("Couldn't allocate Process %d\n",i);
		}
	}
	
	if(flagprogress){
	optimize(processSize,m,memBlock,n,flag);
	}
	else{
	printf("\nEvery process was allocated !");
	}
printf("\n");
}

void optimize(int processSize[],int m,int memBlock[],int n,int flag[]){

int sum=0,i;
	for(i=0;i<n;i++){
		sum+=memBlock[i];
	}
for(i=0;(i<m && sum>0);i++){
	if(processSize[i]!=-1 && sum>=processSize[i]){
		printf("\n The Process - %d was allocated space of %d.",i,processSize[i]);
		sum-=processSize[i];
	}
}

}

int main(){
	int processSize[max];
	int memBlock[max];
	int m;
	int n;
	printf("Enter the number of process : ");
	scanf("%d", &m);

	printf("Enter the process size : \n");
	for (int i = 0; i < m; i++){
		scanf("%d", &(processSize[i]));
	}

	printf("Enter the number of memory block : ");
	scanf("%d", &n);

	printf("Enter the memory size : \n");
	for (int i = 0; i < n; i++){
		scanf("%d", &(memBlock[i]));
	}

	allocateMem(processSize,m,memBlock,n);
	
	return 0;
}

