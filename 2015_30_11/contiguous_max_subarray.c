#include<stdio.h>
#include<conio.h>
void max_subarray(int *a,int n);
int main()
{
   int i,n,a[50];
   printf("enter the size of array");
   scanf("%d",&n);
   printf("enter the elements into array");
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   max_subarray(a,n);
   return 0;
}
void max_subarray(int *a,int n)
{
   int start_index,end_index,start_index_so_far = 0;

   int maxSum = 0,sum = 0,i;
   for(i = 0;i<n;i++)
   {
     sum = sum + a[i];
     if(sum < 0)
     {
        sum = 0;
        start_index_so_far = i+1;
     }
     else if(sum > maxSum)
     {
        maxSum = sum;
        start_index = start_index_so_far;
        end_index = i;
     }
   }
   printf("maxsum is %d\n",maxSum);
   for(i=start_index;i<=end_index;i++)
   {
       printf("%d\n",a[i]);
   }

}
