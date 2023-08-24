#include<stdio.h>
#include<conio.h>
#include<time.h>
int binary(int item, int a[],int low,int high)
{
int mid;
mid=(low+high)/2;
delay(10);
if(low>high)
return 0;
if(a[mid]==item)
return mid+1;
else if(a[mid]>item)
return binary(item,a,low,mid-1);
else
return binary(item,a,mid+1,high);
}

int linear(int item, int n, int a[])
{
int i;
for(i=0;i<n;i++)
{
delay(1);
if(a[i]==item)
return i+1;
}

return 0;
}
void sort(int a[], int n)
{
int i, j, temp;
for(i=0;i<n-1;i++)
for(j=i+1;j<n;j++)
if(a[i]>a[j])
{
    temp=a[i];
a[i]=a[j];
a[j]=temp;
}
void main()
{

int a[10000],n,pos,item, i, opt;
clock_t start, end;
double time;
clrscr();
printf("Enter the array size:");
scanf("%d",&n);
printf("\nElements are:\n");
for(i=0;i<n;i++)
{
    a[i]=(int)rand()%1000;
    printf("%d\t", a[i]);

}
for(;;)
{
a[i]=(int)rand()%1000;
printf("%d\t", a[i]);
printf("\n1. Binary Search \n2. Linear Search \n3. Exit");
printf("\nEnter your option:");
scanf("%d",&opt);
switch(opt)
{
case 1:
sort(a,n);
printf("\nSorted list:\n");

for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("Enter the key element:");
scanf("%d",&item);
start=clock();
pos=binary(item,a,0,n-1);
end=clock();
break;
case 2:
printf ("Enter the Element to be searched:\n");
scanf ("%d",&item);
start=clock();
pos=linear(item,n,a);
end=clock();
break;
default : exit(0);
}
if(pos==0)
printf("Item not found\n");
else
printf("Item found at the position %d",pos);
time=(end-start)/CLK_TCK;
printf("\n Time taken = %f", time);

   }
}









