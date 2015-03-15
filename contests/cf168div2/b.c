// File Name: b.c
// Author: darkdream
// Created Time: 2013年02月20日 星期三 23时58分59秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

char s[52][52];
int  b[52][52] ={0};
int c[2501],d[2501];
int find(int x1,int y1,int x2,int y2)
{
   int temp,i;
  printf("%d %d %d %d\n",x1,y1,x2,y2);
   if(y1 >=y2)
  {
    temp = y1;
	y1 = y2;
	y2 = temp;
  }
   int p = 0;
   for(i = y1; i <= y2; i++ )
	   if (b[x1][i] == 0)
	   p = 1;

    
   if (p == 0)
	   for(i = x1; i<= x2 ;i++)
		   if(b[i][y2] == 0)
		   p =1 ;
   if (p == 0)
	   return 1;



   p = 0;
   for(i = y1; i <= y2; i++ )
	   if (b[x2][i] == 0)
	    p = 1;
	  

   if (p == 0)
	   for(i = x1; i<= x2 ;i++)
		   if(b[i][y1] == 0)
		   	   p =1 ;
                
   if(p ==0)
	  return 1;
  printf("%d %d %d %d\n",x1,y1,x2,y2);
  return 0;
  
}

int main(){

	int n , m ,i , j ,k,t , p = 0;
  scanf("%d %d",&n,&m);
  getchar();
  for (i = 1; i<= n ;i++) 
   gets(s[i]);
  for (i = 1;i <= n; i++)
  {
    for (j = 0 ; j< m; j++)
		if(s[i][j] == 'W')
          b[i][j+1] =  0;
		else 
		  b[i][j+1] =  1;
  }
  
   k = 0;
  for (i = 1;i <= n;i++)
	  for (j = 1; j<= m ;j++)
	  {
	      if (b[i][j] ==1)
		  {	  c[++k] = i;
              d[k] = j;
		  }
	  }
  for (i = 1;i <= k ;i++)
	  printf("%d %d\n",c[i],d[i]);
  for (i =1 ;i <= k ;i++)
	  for (j = i+1 ;j <= k;j++)
	  {
	    if(!find(c[i],d[i],c[j],d[j]))
        {
			printf("NO");
           return 0;
		}
	  }
  printf("YES");

  return 0 ;
}
