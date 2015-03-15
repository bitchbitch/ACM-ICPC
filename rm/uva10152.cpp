#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct node
{
  char s[1000];
  struct node *last ,*next;
};
struct node a[300];
struct node b[300];
int c[300];
int d[300];
int cmp(const void *a ,const void *b)
{
   return *(int *)a - *(int*)b;
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
     memset(a,0,sizeof(a));
     memset(b,0,sizeof(b));
     int n;
     scanf("%d",&n);
     getchar();
     struct node *heada ,*pa,*headb,*pb,*ha,*hb;
     for(int i = 1;i <= n; i ++)
        gets(a[i].s);
     for(int i = 1;i <= n; i ++)
        gets(b[i].s);
     for(int i = n; i >= 1;i --)
      {
        for(int j = n;j >= 1; j--)
          {
            if(strcmp(a[i].s,b[j].s) == 0)
              c[n-i+1] = n-j+1 ;
          }
      }

      int temp = 0 ;
      int k = 0 ;
      for(int i = 1;i <= n;i ++ )
         {
            if(c[i] - temp == 1)
              temp = c[i];
            else
             d[k++] = c[i];

         }
      qsort(d,k,sizeof(int),cmp);
      for(int i = 0 ;i < k; i ++)
         puts(b[n-d[i]+1].s);

      printf("\n");
   }
  return 0;
}

