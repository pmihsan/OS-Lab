#include<stdio.h>

void nextFit(int block[], int process[], int m, int n){
    int alloc[n]; // For checking whether the block is allocated or not
    for(int i=0;i<n;i++){
        alloc[i] = -1;
    }
    // Choose The next fit index and assign process the memory block
    int j = 0;
    for(int i=0;i<n;i++){
        while(j < m){
            if(block[j] >= process[i]){
                alloc[i] = j;
                block[j] -= process[i];
                break;
            }
            j = (j + 1) % m;
        }
    }
    printf("Process\tProcess Size\tBlock no\n");
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
    int block[] = { 5, 10, 20 };
    int process[] = { 10, 20, 5 };
    int m = sizeof(block)/sizeof(block[0]);
    int n = sizeof(process)/sizeof(process[0]);

    nextFit(block, process, m, n);
}