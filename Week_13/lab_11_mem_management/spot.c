#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define max 10

int allocateMem(int processSize[],int m,int memBlock[],int n){
	int sum=0,i;
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
	for(i=0;i<n;i++){
		sum+=memBlock[i];
	}
return sum;
}

int main(){
	int processSize[max];
	int memBlock[max],memBlock_solid[max];
	int m;
	int n,i;
	int sum = 0;
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
		memBlock_solid[i] = memBlock[i];
	}

	sum = allocateMem(processSize,m,memBlock,n);
	printf("\n The Total Memory present after compaction is: %d\n",sum);
	int in;
	printf("\nEnter the size of the next incoming process (Press -1 to indicate that no more processes are yet to come): ");
	while(true){
		printf("\nEnter the size of the next incoming process: ");
		scanf("%d",&in);
		if(in==-1){
		break;
		}
		if(sum>=in){
		printf("\nThe Process was allocated space it required.");
		sum-=in;
		printf("\n The Total Memory present after deallocation is: %d\n",sum);
		}

		else{
		int c;
		for(i=0;i<n;i++){
			printf("\nDo you want to deallocate memory of procses present in Block %d? (Press 1 or 0): ",i+1);
			scanf("%d",&c);
			if(c==1){
				sum+=memBlock_solid[i];
				printf("\n The Total Memory present after allocation is: %d\n",sum);
				if(sum>=in){
					break;
				}
			}
		}
		if(i==n){
		printf("\nThe Process can never be accomadated!");
		}

		printf("\nThe Process was allocated space it required.");
		sum-=in;
		printf("\n The Total Memory present after deallocation is: %d\n",sum);
		
		}
	}

	return 0;
}

