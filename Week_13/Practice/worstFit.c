#include<stdio.h>

void worstFit(int block[], int process[], int m, int n){
    int alloc[n]; // For checking whether the block is allocated or not
    for(int i=0;i<n;i++){
        alloc[i] = -1;
    }
    // Choose The worst fit index
    for(int i=0;i<n;i++){
        int worstInd = -1;
        for(int j=0;j<m;j++){
            if(block[j] >= process[i]){
                if(worstInd == -1){
                    worstInd = j;
                }
                else if(block[worstInd] < block[j]){
                    worstInd = j;
                }
            }
        }
        if(worstInd != -1){
            alloc[i] = worstInd;
            block[worstInd] -= process[i]; 
        }
    }
    printf("Process\tProcess Size\tRemaining Block Size\tBlock no\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(alloc[i] != -1){
            printf("%d\n",alloc[i]+1);
        }
        else{
            printf("Not Allocated\n");
        }
    }

}

void main(){
    int block[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    int m = sizeof(block)/sizeof(block[0]);
    int n = sizeof(process)/sizeof(process[0]);

    worstFit(block, process, m, n);
}