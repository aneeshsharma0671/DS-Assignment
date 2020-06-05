/*
Name- Aneesh sharma
branch- IT 
Roll no. - 11912055
file created on - !7th May 
*/

#include<stdio.h>
#include<time.h>
#include<string.h>

void merge(char str[],int lower,int middle,int upper)
{
    int x= middle-lower+1;
    int y=upper-middle;
    char left[x],right[y];
   
    for (int i = 0; i < x; i++)
    {
        left[i]=str[lower+i];
    }
    
    for(int j=0;j<y;j++){
        right[j]=str[middle+1+j];
    }
   
    int i=0,j=0,k=lower;
   
    while(i<x && j<y){
       
        if(left[i]<=right[j]){
            str[k++] = left[i++];
        }
        else{
            str[k++]=right[j++];
        }
    }
   
    for(;i<x;i++){
        str[k++]=left[i];
    }
    
    for(;j<y;j++){
        str[k++] = right[j];
    }
    
}


void MergeSort(char str[],int lower,int upper){
    if(lower<upper){
        int middle =(upper+lower)/2;
        MergeSort(str,lower,middle);
        MergeSort(str,middle+1,upper);
        merge(str,lower,middle,upper);
    }
}

int main()
{
    char str[]={"Polynomial"};
    char str2[]={"Test Case"};
    int n= strlen("Polynomial");
    int x=strlen("Text Case");
    clock_t t = clock();
    MergeSort(str,0,n);
    MergeSort(str2,0,n);
    
    t=clock()-t;
    long double time_taken = ((double)t)/CLOCKS_PER_SEC;
   
    printf("Time Taken = %Lf\n",time_taken);
   
    for (int i = 0; i < n; i++)
    {
        printf("%c\t",str[i]);
    }
    printf("\n");
   for (int i = 0; i < x; i++)
    {
        printf("%c\t",str2[i]);
    }
    printf("\n");
    return 0;
}
