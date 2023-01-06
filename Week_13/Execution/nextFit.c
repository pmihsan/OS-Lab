#include<stdio.h>

void nextFit(int b[], int pro[], int m, int n){
	int alloc[n];
	for(int  i=0;i<n;i++){
		alloc[i] = -1;
	}
	int j = 0,c;
	for(int i=0;i<n;i++){
		c = 0;
		while(j < m){
			if(c == n) break;
			if(b[j] >= pro[i]){
				printf("Process %d of size %d is allocated to the block %d of size %d so remaining free size => %d\n",i+1,pro[i],j+1,b[j],b[j]-pro[i]);
				alloc[i] = j;
				b[j] -= pro[i];
				break;
			}
			c++;
			j = (j + 1) % m;
		}
		if(c <= n) j = (j + 1) % m;
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
	nextFit(block,processess,m,n);
}
