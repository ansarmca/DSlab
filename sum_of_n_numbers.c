#include<stdio.h>
int main()
{
  int n, i = 1, Sum = 0;
  
  printf("\nEnter a Number: ");
  scanf("%d", &n);
  
  while(i <= n)
  {
     Sum = Sum + i;
     i++;
  }
  
  printf("Sum of %d numbers = %d \n",n, Sum);
  return 0;
}
