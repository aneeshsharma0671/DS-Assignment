#include<stdio.h>
#include<time.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void bubble(int arr[],int upper){
    for (int i = 0; i < upper-1; i++)
    {
        for (int j = 0; j < upper-i-1; j++)
            if(arr[j]>arr[j+1]){
                swap(&arr[j+1],&arr[j]);
            }
    }
}

int main(){
    int arr[1000];
    for (int p = 1000; p < 0; p--)
    {
        arr[p]=p;
    }
    
    clock_t t = clock();
    bubble(arr,1000);
    t=clock()-t;
    long double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time Taken = %Lf\n",time_taken);
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t",arr[4]);
    }
    return 0;
}