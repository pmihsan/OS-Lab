#include<stdio.h>
#include<stdlib.h>
#include"../sort.h"
int n;

void scan(int arr[], int head, int pos){
	int seek = 0;
	for(int i=pos;i<=n;i++){
		//printf("(%d -- %d(%d))",arr[i],head,abs(arr[i]-head));
		printf("(%d -- %d)",arr[i],head);
		seek += abs(arr[i] - head);
		head = arr[i];
	}
	for(int i=pos-1;i>=0;i--){
		//printf("(%d -- %d(%d))",arr[i],head,abs(arr[i]-head));
		printf("(%d -- %d)",arr[i],head);
		seek += abs(arr[i] - head);
		head = arr[i];
	}
	printf("\nTotal number of seek operations %d\n",seek);
	printf("They are serviced starting from the head and then moves back and forth\n");
//	printf("Average seek time %.3f\n",(float)seek/n);
	}

void main(){
	printf("Enter n:\n");
	scanf("%d",&n);
	int arr[n+1];
	int head,pos = 0;
	printf("Enter the cylinder number\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}	
	sort(arr,n);
	arr[n] = 199;
	printf("Enter the initial head position\n");
	scanf("%d",&head);
	for(int i=0;i<=n;i++){
		if(head < arr[i]){
			break;
		}
		pos++;
	}
	scan(arr,head,pos);
}
