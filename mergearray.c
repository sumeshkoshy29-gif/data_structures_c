#include<stdio.h>
int main()
{
int a[5],b[50],c[100];
int n,m,i;
printf("enter the number of elements of the first array:\n");
scanf("%d", &n);
printf("enter the elements of the first array:\n");
for(i=0;i<n;i++)
{
scanf("%d", &a[i]);
c[i]=a[i];
}
printf("enter the number of elements of the second array:");
scanf("%d",&m);
printf("enter elements of second array:\n");
for(i=0;i<m;i++)
{
c[n+i]=b[i];
}
printf("Merged array:\n");
for(i=0;i<n+m;i++)
{
printf("%d",c[i]);
}
return 0;
}




