#include<stdio.h>
#include<stdlib.h>
void sort(int *arr, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    int total_head_movement=0,initial_pos;
    int n;
    printf("\n Enter the no. of cylinders in Request queue:\n");
    scanf("%d",&n); // Total count of cylinders
    int request_queue[n+1]; 
    printf("\n Enter the cylinders no. in Request queue :\n");
    for(int i=0;i<n;i++)
     scanf("%d",&request_queue[i]);
    request_queue[n] = 199;
    printf("\n Enter the initial Position of RW head: ");
    scanf("%d",&initial_pos);
    sort(request_queue, n+1);
    int pos = 0;
    for(int i=0; i<n+1; i++)
    {
        pos++;
        if(request_queue[i] > initial_pos)
            break;
    }
    for(int i=pos-1; i<n+1; i++)
    {
        printf("(%d - %d)", request_queue[i], initial_pos);
        total_head_movement += abs(initial_pos - request_queue[i]);
        initial_pos = request_queue[i];
    }
    total_head_movement = total_head_movement + 199-0;
    initial_pos = 0;
    for(int i=0; i<pos-1; i++)
    {
        printf("(%d - %d)", initial_pos,request_queue[i]);
        total_head_movement += abs(initial_pos - request_queue[i]);
        initial_pos = request_queue[i];
    }

   printf("\nTotal No. of Head Movements = %d\n",total_head_movement);
   printf("\nAverage head movements = %.2f\n",(float)total_head_movement/n);    

   return 0;
}