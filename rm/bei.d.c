#include <stdio.h>
#include <math.h>
int min(int x, int y)
{
  return x>=y?y:x;
}
int pw(int n,int t)
{
  int i , s = 1;
  for (i = 1 ; i <= t; i++  )
	  s = s*n;
   return s;

}
int main()
{
   int a[11]={2,3,5,7,11,13,17,19,23,29,31};
   int x,y;
   while (scanf("%d %d", &x, &y) != EOF)
   {
      int i , j , k = 1 ,t = y ; 
      int c[11]={0},b[11]={0};
	  for(i = 0 ; i < 11 ; i ++)
	  {
	     if(x %a[i] == 0 )
		   {	 c[i]++;
		        x = x / a[i];
				i = i - 1;
		   }
         if (x == 1)
			 break;
	  }
   for(i = 0 ; i < 11 ; i ++)
	  {
	     if(y % a[i] == 0 )
		   {	 b[i]++;
		    	y = y / a[i];
				i = i - 1;
		   }
		 if (y == 1)
			 break;
		 
	  }
	  for (i = 0 ; i < 11; i ++)
		  b[i]=b[i]*t;
	  for (i =0 ; i < 11 ; i ++)
		  k = k*pw(a[i],min(c[i],b[i]));
		
	  printf("%d\n",k);

   }
return 0;


}
