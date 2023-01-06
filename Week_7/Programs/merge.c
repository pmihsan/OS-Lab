#include<stdio.h>
int n;
void printArray(int arr[]){
    printf("The Array elements are\n");
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void mergeInPlace(int arr[], int s, int m, int e) {
        int len = e - s;
        int mix[len];
        int i = s;
        int j = m;
        int k = 0;
        while (i < m && j < e) {
            if (arr[i] < arr[j]) {
                mix[k] = arr[i];
                i++;
            } else {
                mix[k] = arr[j];
                j++;
            }
            k++;
        }
        // it may be possible that one of the arrays is not complete
        // copy the remaining elements
        while (i < m) {
            mix[k] = arr[i];
            i++;
            k++;
        }
        while (j < e) {
            mix[k] = arr[j];
            j++;
            k++;
        }
        for (int l = 0; l < len; l++) {
            arr[s+l] = mix[l];
        }
}

void mergeSort(int arr[], int s, int e) {
        if (e - s == 1) {
            return;
        }
        int mid = (s + e) / 2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid, e);
        mergeInPlace(arr, s, mid, e);
}
int main(){
    printf("Enter the size of the array\n");
    scanf("%d",&n);   
    int arr[n];
    int start = 0;
    printf("Enter the arrays elements\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printArray(arr);
    printf("Merge Sort Algorithm\n");
    mergeSort(arr,start,n);
    printArray(arr);
    return 0;
}
