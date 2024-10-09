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
  
  printf("Sum of N Numbers = %d \n ", Sum);
  return 0;
}
