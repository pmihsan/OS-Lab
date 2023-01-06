#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define max 10

void allocateMem(int processSize[],int m,int memBlock[],int n){
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
			printf("Allocated Process %d[%d] at %d[%d] block\n",i,processSize[i],minIndex + 1,memBlock[minIndex]);
			memBlock[minIndex] -= processSize[i];
		}
		else	
			printf("Couldn't allocate Process %d\n",i);
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

