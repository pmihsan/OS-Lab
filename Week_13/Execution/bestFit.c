#include<stdio.h>

void bestFit(int b[], int pro[], int m, int n){
	int alloc[n];
	for(int  i=0;i<n;i++){
		alloc[i] = -1;
	}
	for(int i=0;i<n;i++){
		int bestIndex = -1;
		for(int j=0;j<m;j++){
			if(b[j] >= pro[i]){
				if(bestIndex == -1) bestIndex = j;
				else if(b[j] < b[bestIndex]) bestIndex = j;
			}
		}
		if(bestIndex != -1){
			alloc[i] = bestIndex;
			printf("Process %d of size %d allocates to block %d of size %d so remaining block size => %d\n",i+1,pro[i],bestIndex+1,b[bestIndex],b[bestIndex]-pro[i]);
			b[bestIndex] -= pro[i];
		}
		else{
			printf("Process %d of size %d is Not Allocated\n",i+1,pro[i]);
		}
	}
	printf("Process\tProcess Size\tBlock no\n");
	for(int i=0;i<n;i++){
		printf("%d\t\t%d\t\t",i+1,pro[i]);
		if(alloc[i] != -1){
			printf("%d\n",alloc[i]+1);
		}
		else{
			printf("Not Allocated\n");
		}
	}
}

void main(){
	int m,n;
	printf("Enter no of blocks and no of process\n");
	scanf("%d %d",&m,&n); 
	int block[m],processess[n];
	printf("Enter the block size\n");
	for(int i=0;i<m;i++){
		scanf("%d",&block[i]);
	}
	printf("Enter the processess size\n");
	for(int j=0;j<n;j++){
		scanf("%d",&processess[j]);
	}
	bestFit(block,processess,m,n);
}
