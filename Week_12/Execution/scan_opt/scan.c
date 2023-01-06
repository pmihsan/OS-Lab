#include<stdio.h>
#include<stdlib.h>
#include"../sort.h"
int n;

void scan(int arr[], int head, int dir){
	int seek = 0,min,max;
	min = max = arr[0];
	for(int i=0;i<n;i++){
		if(arr[i] < min){
			min = arr[i];
		}
		if(arr[i] > max){
			max = arr[i];
		}
	}
	if(dir == 1){
		seek = (arr[n] - head) + (arr[n] - min);
		printf("(%d -- %d)(%d -- %d)",arr[n],head,arr[n],min);
	}
	else{
		seek = (head - 0) + (max - 0);
		printf("(%d -- 0)(%d -- 0)",head,max);
	}
	printf("\nTotal number of seek operations %d\n",seek);
	printf("They are serviced starting from the head and then moves back and forth\n");
//	printf("Average seek time %.3f\n",(float)seek/n);
	}

void main(){
	printf("Enter n:\n");
	scanf("%d",&n);
	int arr[n+1];
	int head,dir = 0;
	printf("Enter the cylinder number\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}	
	sort(arr,n);
	arr[n] = 199;
	printf("Enter the initial head position\n");
	scanf("%d",&head);
	printf("Enter direction:\n");
	scanf("%d",&dir);
	scan(arr,head,dir);
}
