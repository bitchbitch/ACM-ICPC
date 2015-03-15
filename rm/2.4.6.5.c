#include <stdio.h>
int main()
{
   void print (int a);
    int a;
   while (scanf("%d",&a) != EOF )
   {
   print(a);
   
  } 

  return 0;
}

void print(int a)
{
  int n[a];
  int i,j,k=0;
  for (i = 0 ; i < a ; i++)
  {
    scanf("%d",&n[i]);

  }
  scanf("%d",&j);
  for (i = 0 ; i < a ; i++)
  {
    if (n[i] < j)
      k++;
  }
  printf("%d\n",k);

}
