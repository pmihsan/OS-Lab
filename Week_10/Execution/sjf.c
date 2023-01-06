#include<stdio.h>
#include<limits.h>

float avg_wt = 0.0;
float avg_tat = 0.0;

void printArray(int arr[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int minProcessIndex(int bt[], int at[], int mc, int n){
	int min = INT_MAX;
	int index = INT_MAX;
	for(int i=0;i<n;i++){
		if(at[i] <= mc && bt[i] < min){
			min = bt[i];
			index = i;
		}
	}
	return index;
}

void findAvgTime(int proc[],int bt[], int at[], int n){
	int tat[n],wt[n];
	int i = 0, mc = 0, m;
	while(i <= n){
		m = minProcessIndex(bt,at,mc,n);
		if(m == INT_MAX){
			i++;
			continue;
		}
		mc += bt[m];
		tat[m] = mc - at[m];
		wt[m] = tat[m] - bt[m];
		at[m] = INT_MAX;
		i++;
	}
	printf("Turn Around Time\n");
	printArray(tat,n);
	printf("Waiting Time\n");
	printArray(wt,n);
	for(int i=0;i<n;i++){
		avg_tat += tat[i];
		avg_wt += wt[i];
	}
	printf("Average Waiting time - %f\n",avg_wt / n);
	printf("Average Turn Around time - %f\n",avg_tat / n);

}	
void main(){
	int proc[] = {1,2,3};
	int bt[] = {4,5,6};
	int at[] = {0,1,2};
	int n = sizeof(proc)/ sizeof(proc[0]);
	findAvgTime(proc,bt,at,n);
} 
