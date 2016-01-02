#include<stdio.h>
#include<conio.h>
void main()
{
    int a[20],b[20],c[20],i,j,n,n1,temp,r,arr[30],k1,k2,k,m;
    printf("enter the size of  1 table");
    scanf("%d",&n);
    printf("Enter an  first integer to find multiplication table: ");
    scanf("%d",&k1);
    for(i=0;i<=n;++i)
    {
        printf("%d * %d = %d\n", k1, i, k1*i);
        a[i]=k1*i;
        printf("%d\n",a[i]);
    }
    printf("enter the size of  2 table");
    scanf("%d",&n1);
    printf("Enter an  second integer to find multiplication table: ");
    scanf("%d",&k2);
    for(i=0;i<=n1;++i)
    {
        printf("%d * %d = %d\n", k2, i, k2*i);
        b[i]=k2*i;
        printf("%d\n",b[i]);
    }

    printf("enter the value of r");
    scanf("%d",&r);

    for(i=0;i<=n;i++)
    {
        c[i]=a[i];
        printf("\n1st array values are %d\n",c[i]);
    }
    j=0;
    m=n+n1;
    for(i=n;i<=m;i++)
    {
        c[i]=b[j];
             printf("\n2nd array values are %d\n",c[i]);
        j++;
    }
    for(i=0;i<=m;i++)
    {
        printf("%d\n",c[i]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(c[j]>c[j+1])
            {
                temp=c[j];
                c[j]=c[j+1];
                c[j+1]=temp;
            }
        }
    }
    for(j=0;j<=m;j++)
    {
        printf("sorted is %d\n",c[j]);
    }
     for (i = 0; i < m; i++) {
      for (j = i + 1; j < m;) {
         if (c[j] == c[i]) {
            for (k = j; k < m; k++) {
               c[k] = c[k + 1];
            }
            m--;
         } else
            j++;
      }
   }

    for (i=0;i<=n+n1;i++){
        printf("%d\n",c[i]);
    }


    printf("the element at rth position is %d",c[r]);

}







