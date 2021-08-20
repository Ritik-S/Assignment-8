/**
 * Program to find Mth smallest number
 * Compilation : gcc mth_smallest.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 04/8/2021
 * Ques 4. Assignment_8
 *
 */
#include<stdio.h>
//function to swap two numbers
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
//return mth smallest number
int mth_smallest_number(int a[],int m)
{
	return a[m-1];
}
// function to partition the array
int partition (int a[], int lb, int rb)
{
    //pivot point is selected 
    int pivot=a[lb];
    int i =lb;
    int j=rb ;
    //basically we are partitioning larger unsorted arrays to two smaller array
    //using a pivot and elements to the left should now be smaller than pivot 
    //and to the right should be greater than pivot 
    while(i<j)
    { 
      while(a[i]<=pivot)
      i++;
      while(a[j]>pivot)
      j--;
      if(i<j)
      swap(&a[i],&a[j]);
    }
    swap(&a[lb],&a[j]);
    return j; 
    
}
//function to quicksort the given array
void quickSort(int arr[], int low, int high)
{
    // code here
    if(low<high)
    {
        int pi=partition(arr, low, high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
    
   
   
int main()
{
    int n ;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    int a[n];
    for(int i = 0 ; i < n ; ++i)
    {
    	scanf("%d",&a[i]);
    }
    int m;
    printf("Enter value of m : ");
    scanf("%d",&m);
    quickSort(a,0,n-1);
    printf("%dth samllest element is %d\n",m,mth_smallest_number(a,m))  ;  
}
