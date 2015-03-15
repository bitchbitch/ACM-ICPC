// File Name: uva10112.c
// Author: darkdream
// Created Time: 2013年03月04日 星期一 09时24分38秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
double  a[20][3];
int n;
double area(int i ,int j , int k)
{
  return  fabs(a[i][1]*a[j][2] + a[k][1]*a[i][2]+a[j][1]*a[k][2] - a[k][1]*a[j][2] - a[i][1]* a[k][2] - a[j][1]*a[i][2])/2 ;
}

int find(int i ,int j , int k)
{
   for(int s = 1; s <= n; s++)
      if(s == i || s == j || s == k )
		   continue;
      else
	  {
	     double p =fabs(area(s,i,j) + area(s,j,k) + area(s,i,k) - area(i,j,k));
		 if(p < 1e-7)
		    return 0 ;
	  
	  }
   return 1;

}


int main(){

  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
   while(scanf("%d",&n),n)
   {   getchar();
	   char temp;
	   int i, j , k ,ti = 0 , tj = 0 ,tk = 0;
	   double max = 0 ;
       for(i = 1;i <= n;  i++)
	   {scanf("%c %lf %lf",&temp,&a[i][1],&a[i][2]);
	     getchar();
	    }
	   for(i = 1 ;i <= n; i ++)
		   for(j = i+1; j<= n ;j++)
			   for(k = j+1; k <= n; k++)
			   if(find(i,j,k))
			   {
			      if(area(i,j,k) > max)
				  {
				   max = area(i,j,k);
				   ti = i ;
				   tj = j ;
				   tk = k ;
				  }
			   
			   }
	   printf("%c%c%c\n",ti+'A' - 1,tj+'A' - 1,tk+'A' - 1);

	   
   }
return 0 ;
}
