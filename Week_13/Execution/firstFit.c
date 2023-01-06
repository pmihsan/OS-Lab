#include<stdio.h>

void firstFit(int b[], int pro[], int m, int n){
	int alloc[n];
	for(int  i=0;i<n;i++){
		alloc[i] = -1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(b[j] >= pro[i]){
				alloc[i] = j;
				printf("Process %d of size %d allocates to block %d of size %d so remaining block size => %d\n",i+1,pro[i],j+1,b[j],b[j]-pro[i]);
				b[j] -= pro[i];
				break;
			}
		}
		if(alloc[i] == -1){
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
	firstFit(block,processess,m,n);
}
