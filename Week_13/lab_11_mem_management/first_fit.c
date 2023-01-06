#include<stdio.h>
#define max 10
int main(){
int bsize[max], psize[max], bno, pno, flags[max], allocation[max], i, j;
 
for(i = 0; i < max; i++)
{
flags[i] = 0;
allocation[i] = -1;
}

printf("Enter no. of blocks: ");
scanf("%d", &bno);
printf("\nEnter size of each block: ");
for(i = 0; i < bno; i++){
scanf("%d", &bsize[i]);
}
 
printf("\nEnter no. of processes: ");
scanf("%d", &pno);

printf("\nEnter size of each process: ");
for(i = 0; i < pno; i++){
	scanf("%d", &psize[i]);
}

for(i = 0; i < pno; i++){         //allocation as per first fit
	for(j = 0; j < bno; j++){
		if(flags[j] == 0 && bsize[j] >= psize[i])
			{
				allocation[j] = i;
				flags[j] = 1;
				break;
			}
	}
}

//display allocation details
printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
for(i = 0; i < bno; i++){
printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
if(flags[i] == 1)
	printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
else
	printf("Not allocated\n");
}
return 0;
}