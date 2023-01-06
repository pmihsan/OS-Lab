#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int n;
void printArray(int a[]){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}

void merge(int a[], int s, int m, int e){
	int len = e - s;
	int mixArray[len];
	int i = s, j = m, k = 0; 
	
	while(i < m && j < e){
		if(a[i] < a[j]){
			mixArray[k] = a[i];
			i++;
		}
		else{
			mixArray[k] = a[j];
			j++;
		}
	k++;
	}
	while(i < m){
		mixArray[k] = a[i];
		i++;k++;
	}
	while(j < e){
		mixArray[k] = a[j];
		j++;k++;
	}
	for(int l=0;l<len;l++){
		a[s+l] = mixArray[l];
	}	
}

void mergeSort(int arr[], int s, int e){
	if(e - s == 1){
		return;
	}
	int m = (s + e) / 2;
	mergeSort(arr, s, m);
	mergeSort(arr, m, e);
	merge(arr, s, m, e);
}

void *thread(void *argp){	
	int *a = (int *)argp;
	printf("Merge Sort\n");
	mergeSort(a,0,n);
	printArray(a);
}

void main(){
	printf("Enter n\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	pthread_t tid;
	pthread_create(&tid,NULL,thread,arr);
	pthread_exit(NULL);
}		
