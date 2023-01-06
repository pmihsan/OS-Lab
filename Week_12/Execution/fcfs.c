#include<stdio.h>
#include<stdlib.h>
int n;

void fcfs(int arr[], int head){
	int seek = 0;
	for(int i=0;i<n;i++){
		printf("(%d -- %d)",arr[i],head);
		seek += abs(arr[i] - head);
		head = arr[i];
	}
	printf("\nTotal number of seek operations %d\n",seek);
	printf("They are serviced in the give order\n");
//	printf("Average seek time %.3f\n",(float)seek/n);
	}

void main(){
	printf("Enter n:\n");
	scanf("%d",&n);
	int arr[n];
	int head;
	printf("Enter the cylinder number\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}	
	printf("Enter the initial head position\n");
	scanf("%d",&head);
	fcfs(arr,head);
}
