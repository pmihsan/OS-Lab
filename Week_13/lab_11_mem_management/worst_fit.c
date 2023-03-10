#include<stdio.h>
#include<string.h>

void worstFit(int blockSize[],int m,int processSize[],int n){
	int allocation[n];
	memset(allocation,-1,sizeof(allocation));
	int i;
	for(i=0;i<n;i++){

		int wi = -1;
		for(int j=0;j<m;j++){
			if(blockSize[j] >=processSize[i]){
				if(wi==-1){
					wi=j;
				}
				else if(blockSize[wi]<blockSize[j]){
					wi = j;
				}
			}
		}
		if(wi!=-1){
			allocation[i]=wi;
			blockSize[wi]-=processSize[i];
		}
	}
		printf("\nProcess No.\tProcess Size\tBlock No\n");

		for(int i=0;i<n;i++){
				printf("%d\t\t%d\t\t",i+1,processSize[i]);
				if(allocation[i]!=-1)
						printf("%d",allocation[i]+1);
				else
						printf("Not Allocated");
				printf("\n");
		}
}

int main(){
		int blockSize[]={100,500,200,300,600};
		int processSize[] = {212,417,112,426};
		int m = sizeof(blockSize)/sizeof(blockSize[0]);
		int n = sizeof(processSize)/sizeof(processSize[0]);
		worstFit(blockSize,m,processSize,n);
		return 0;
}

