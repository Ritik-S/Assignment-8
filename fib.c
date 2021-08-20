/**
 * Program to Print n numbers in Fibonacci series that are even.
 * Compilation : gcc fib.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 04/8/2021
 * Ques 4. Assignment_8
 *
 */

#include<stdio.h>
const int maxN=1e5;
//memo array is used to memoize result of fibbonacci sequence
int memo[100000];
//function to Print n numbers in Fibonacci series that are even.
void fibbonacci(int index, int n , int count)
{
    //we have already calculated answer for previous terms and memoized them and we used them to calculate our answer
    memo[index] = memo[index - 1] + memo[index - 2];
    //(a&1^1) is just similar (a%2==0) or to check if the number is even  
    if(((memo[index]&1)^1))
    {
    	printf("%d ",memo[index]);
    	count++;
    }
    //after printing n numbers return 
    if(count >= n){
       return;
    }
  
  
    fibbonacci(index + 1 , n ,count);
}

void fib(int n) {
    //we need to give first 2 values
    memo[1] = 1;
    memo[2] = 1;
    fibbonacci(3,n,0);
}

int main()
{
    int n ;
    printf("Enter n = ");
    scanf("%d",&n);
    fib(n);

}

