#include<stdio.h>

void sort(int arr[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j>0;j--){
			if(arr[j-1] > arr[j]){
				int t = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = t;
			}
		}
	}
}
/*
void main(){
	int arr[] = {2,5,1,5,6};
	sort(arr,5);
	for(int i=0;i<5;i++){
 		printf("%d ",arr[i]);
	}
}*/
