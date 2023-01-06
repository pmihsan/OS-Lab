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

int highPriorityIndex(int pr[], int at[], int mc, int n){
	int min = INT_MAX;
	int index = INT_MAX;
	for(int i=0;i<n;i++){
		if(at[i] <= mc && pr[i] < min){
			min = pr[i];
			index = i;
		}
	}
	return index;
}

void findAvgTime(int proc[],int bt[], int at[], int pr[], int n){
	int tat[n],wt[n];
	int i = 0, mc = 0, m;
	while(i <= n){
		m = highPriorityIndex(pr,at,mc,n);
		if(m == INT_MAX){
			i++;
			continue;
		}
		mc += bt[m];
		tat[m] = mc - at[m];
		wt[m] = tat[m] - bt[m];
		pr[m] = INT_MAX;
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
	int bt[] = {3,6,5};
	int at[] = {1,0,2};
	int pr[] = {2,1,3};
	int n = sizeof(proc)/ sizeof(proc[0]);
	findAvgTime(proc,bt,at,pr,n);
} 
