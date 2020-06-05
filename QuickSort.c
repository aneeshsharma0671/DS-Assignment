/*
Name- Aneesh sharma
branch- IT 
Roll no. - 11912055
file created on - !7th May 
*/

#include<stdio.h>
#include<time.h>
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


int divide(int arr[],int lower,int upper){
    int i = lower-1;
    int middle = arr[upper];
    for (int j = lower; j < upper; j++)
    {
        if(middle>arr[j]){              
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[upper]);
    return i+1; 
}


void quick(int arr[],int lower,int upper){
    if(lower<upper){
        int divideition = divide(arr,lower,upper);
        quick(arr,lower,partition-1);
        quick(arr,partition+1,upper);
    }
}

int main(){
    int arr[1000];
    for (int i = 1000; i < 0; i--)
    {
        arr[i]=i;
    }
    clock_t t = clock();
    quick(arr,0,1000);
    t=clock()-t;
    long double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time Taken = %Lf\n",time_taken);
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}
