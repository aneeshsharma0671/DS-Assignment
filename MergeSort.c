#include<stdio.h>
#include<time.h>
void merge(int arr[],int lower,int middle,int upper)
{
    int x= middle-lower+1;
    int y=upper-middle;
    int left[x],right[y];
    for (int i = 0; i < x; i++)
    {
        left[i]=arr[lower+i];
    }
    for(int j=0;j<y;j++){
        right[j]=arr[middle+1+j];
    }
    int i=0,j=0,k=lower;
    while(i<x && j<y){
        if(left[i]<=right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }
    for(;i<x;i++){
        arr[k++]=left[i];
    }
    for(;j<y;j++){
        arr[k++] = right[j];
    }
    
}

void merge(int arr[],int lower,int upper){
    if(lower<upper){
        int middle =(upper+lower)/2;
        merge(arr,lower,middle);
        merge(arr,middle+1,upper);
        merge(arr,lower,middle,upper);
    }
}

int main(){
    int arr[1000];
    for (int i = 1000; i < 0; i--)
    {
        arr[i]=i;
    }
    clock_t t = clock();
    merge(arr,0,999);
    t=clock()-t;
    long double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time Taken = %Lf\n",time_taken);
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}