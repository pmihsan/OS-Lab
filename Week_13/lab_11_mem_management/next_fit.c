#include <stdio.h>
#include <stdbool.h>

void allocateMem(int processSize[],int m,int memBlock[],int n){
	bool flag = false;
	int j = 0;
	for (int i = 0; i < m; i++){
		int ct = n;
		while (ct--) {
			if (processSize[i] <= memBlock[j]){
				printf("Allocated Process %d[%d] at %d[%d] block\n",i+1,processSize[i],j + 1,memBlock[j]);
				memBlock[j] -= processSize[i];
				flag = true;
				break;
			}
			j = (j + 1) % n;
		}
		if (!flag)
			printf("Couldn't allocate Process %d\n",i);
		flag = false;
	}
}

int main(){
	int processSize[] = { 10, 20, 5 };
	int memBlock[] = { 5, 10, 20 };
	int m = sizeof(processSize) / sizeof(int);
	int n = sizeof(memBlock) / sizeof(int);
	allocateMem(processSize,m,memBlock,n);
	return 0;
}

