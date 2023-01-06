#include<stdio.h>

int main()	{
	int n,bt[20],wt[20],tat[20],at[20],i,j,id[20] ; 
	float avgwt=0,avgtat=0 ; 
	printf("Enter the number of processes [MAX - 20]: ") ; 
	scanf("%d", &n) ; 
	
	printf("Enter process BT, AT\n") ; 
	for(i = 0 ; i < n ; i++)	{
		printf("For P[%d] : ",i+1) ; 
		scanf("%d",&bt[i]) ; 
		scanf("%d",&at[i]) ; 

	}
	for(i = 0 ; i<n; i++)	{
		printf("%d ",at[i]) ;
	      }	
	for(i = 0 ; i < n ; i++)	{
		id[i]=i+1 ; 
	}
	//FFCFS- 1) that which comes first is served first.
	//so we shoukld first try sorting the processes based on their arrival times.
	//after that we should find waiting time and tat.
	for(i = 0 ; i < n ; i++)	{
		for(j = 0 ; j < n-1; j++)	{
			if(at[j] > at[j+1])	{
				int t = at[j] ; 
				at[j] = at[j+1] ; 
				at[j+1] = t ;

				t = id[j] ; 
				id[j] = id[j+1] ; 
				id[j+1] = t ;

				t = bt[j] ; 
				bt[j] = bt[j+1] ;
				bt[j+1] = t ; 
			}
		}
	}

	
	for(i = 0 ; i<n; i++)	{
		printf("%d ",at[i]) ;
	      }	

	wt[0] = 0 ; 
	for(i = 1; i<n; i++)	{
		wt[i] = wt[i-1]+bt[i-1] ;  
	}
	printf("\nProcess\t\tBurst Time\tArrival Time\tWaiting Time\tTurnaround time\n") ;
	if(n <= 1)	{
		tat[i] = bt[i] ; 
		wt[i] = 0 ; 
	}
	else	{
		for(i = 0 ; i < n ; i++)	{
			tat[i] = bt[i]+wt[i]-at[i] ; 
			wt[i] = wt[i]-at[i] ; 
			avgwt+=wt[i] ; 
			avgtat+=tat[i] ; 	
	//		printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d",id[i],bt[i],at[i],wt[i],tat[i]) ; 
		}
	}
	for(i = 0 ; i < n ; i++)	{
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d",id[i],bt[i],at[i],wt[i],tat[i]) ; 
	}
	avgwt /= n ; 
	avgtat /= n ; 
	printf("\nAverage waiting time : %f\n",avgwt) ; 
	printf("Average turnaround time : %f\n",avgtat) ; 
	printf("\n\n") ; 
	return 0 ; 
}
