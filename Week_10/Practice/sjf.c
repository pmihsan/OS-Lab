#include<stdio.h>
#include<limits.h>
int minInd(int [],int,int,int []);
int main(){
	int n,i;
	printf("\nEnter the no of processes:\n");
	scanf("%d",&n);

	int bt[n],at[n],tat[n],wt[n];
	
	for(i=0;i<n;i++){
		printf("Enter the Burst Time for Process - %d\n",i+1);
		scanf("%d",&bt[i]);

		printf("Enter the Arrival Time for Process - %d\n",i+1);
		scanf("%d",&at[i]);
	}

	i=0;
	int mc = 0,m;
	while(i<=n){
		m = minInd(bt,mc,n,at);
		if(m==INT_MAX){
			i++;
			continue;
		}
		mc+=bt[m];
		tat[m] = mc-at[m];
		wt[m] = tat[m]-bt[m];
		at[m] = INT_MAX;
		i++;
	}
	double avg_wt=0.0;
	int avg_tat=0;
	for(i=0;i<n;i++){
		avg_wt+=wt[i];
		avg_tat+=tat[i];
	}
	avg_wt = avg_wt/n;
	avg_tat = avg_tat/n;

	printf("The average wt was found to be: %lf\n",avg_wt);
	printf("The Avg TAT was found to be: %d\n",avg_tat);

	return 0;
}

int minInd(int bt[],int mc,int n,int at[]){
	int mi = INT_MAX,ind=INT_MAX,i;
	for(i=0;i<n;i++){
		if(bt[i]<mi && at[i]<=mc){
				mi = bt[i];
				ind = i;
		}
	}
	return ind;
}		
