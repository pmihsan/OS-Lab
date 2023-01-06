#include<stdio.h>
#include<limits.h>
#define max 20 
int main()
{
	int fragment[max],b[max],p[max],i,j,nb,np,temp,lowest=INT_MAX;
	int barray[max],parray[max];

	printf("\nEnter the number of blocks:");
	scanf("%d",&nb);
	printf("Enter the number of processes:");
	scanf("%d",&np);
	for(i=0;i<nb;i++){
	barray[i]=0;
	}
	printf("\nEnter the size of the blocks:-\n");
	for(i=0;i<nb;i++){
		printf("Block no.%d:",i+1);
	        scanf("%d",&b[i]);
    	}

	printf("\nEnter the size of the processes :-\n");

	for(i=0;i<np;i++){
        printf("Process no.%d:",i+1);
        scanf("%d",&p[i]);
 	}

	for(i=0;i<np;i++){

		for(j=0;j<nb;j++){

			if(barray[j]!=1){
				temp=b[j]-p[i];
				if(temp>=0 && lowest>temp){
					parray[i]=j;
					lowest=temp;
				}
			}
		}

	fragment[i]=lowest;
	barray[parray[i]]=1;
	lowest=INT_MAX;
	}

	printf("\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tRem Fragment size");

	for(i=0;i<np && parray[i]!=0;i++){
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d",i,p[i],parray[i],b[parray[i]],fragment[i]);
	}
	printf("\n");
return 0;
}

