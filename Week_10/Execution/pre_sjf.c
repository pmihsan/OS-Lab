#include<stdio.h>
struct process { int WT,AT,BT,TAT; }a[10];
int main(){
	int n,temp[10],t,count=0,short_p;
	float totalWT=0,totalTAT=0,avgWT,avgTAT;
	printf("Enter no of processess\n");
	scanf("%d",&n);
	printf("Enter Arrival time,Burst Time\n");
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i].AT,&a[i].BT);
		temp[i] = a[i].BT;
	}
	a[9].BT = 10000;
	for(t =0;count !=n ;t++){
		short_p = 9;
		for(int i=0;i<n;i++){
			if(a[short_p].BT > a[i].BT && a[i].AT <= t && a[i].BT > 0){
				short_p = i;
			}
		}
		a[short_p].BT = a[short_p].BT - 1;
		if(a[short_p].BT == 0){
			count++;
			a[short_p].WT = t+1 - a[short_p].AT - temp[short_p];
			a[short_p].TAT = t+1 - a[short_p].AT;
			totalWT += a[short_p].WT;
			totalTAT += a[short_p].TAT;
		}
	}
	printf("ID WT TAT\n");
	for(int i=0;i<n;i++){
		printf("%d %d %d\n",i+1,a[i].WT,a[i].TAT);
	}
	printf("Avg Waiting Time - %f\n",totalWT/n);
	printf("Avg TurnAround Time - %f\n",totalTAT/n);
	
	return 0; 
}
