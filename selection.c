#include<stdio.h>

int main()
{
  int n,i,j,temp,arr[20];
  printf("enter the number of elements\n");
  scanf("%d",&n);

  printf("enter the elements\n");

  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }

   for(i=0;i<n;i++)
   {
     for(j=i+1;j<n;j++)
     {
       if(arr[i]>arr[j])
       {
          temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
        }
       }
    }

    printf("Sorted elements are\n");
    for(i=0;i<n;i++)
    {
      printf("%d ",arr[i]);

    }


    return 0;


}
