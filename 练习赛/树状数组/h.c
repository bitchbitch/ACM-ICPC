// File Name: h.c
// Author: darkdream
// Created Time: 2013年03月22日 星期五 20时05分55秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int N ;
int c[1005][1005];
int lowbit(int x)
{
    return x&(-x);
}
void update(int x, int y ,int i)
{
 while(x <= N )
 {
  int ty = y;
  while(ty <= N )
  {
    c[x][ty] += i ;
	ty += lowbit(ty);
  }
  x += lowbit(x);
 }

}
int read(int x, int y )
{
  int res =0 ;
  while(x >= 1)
  { int ty = y;
  while(ty >= 1)
  {
     res  += c[x][ty];
	 ty -= lowbit(ty);
  }
   x -= lowbit(x);
  }
  return res;
}
int main(){
    //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
    int t; 
	scanf("%d",&t);
	for(int k = 1;k <= t; k ++)
	{
     memset(c,0,sizeof(c));
	 if(k != 1)
		 printf("\n");
	 int  m ;
	 char ch[10] ;
      scanf("%d %d",&N,&m);
	  getchar();
      for(int i = 1; i <= m ; i++)
	  {
		  int x1,x2, y1 ,y2;
		  scanf("%s",ch);
		  if(ch[0] == 'Q')
		  {
		    scanf("%d %d",&x1,&y1);
			getchar();
			 if(read(x1,y1) %2 == 0)
				 printf("0\n");
			 else
				 printf("1\n");

		  }
		  else
		  {
		     scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			  getchar();
			  x2++;
			  y2++;
		        update(x1,y1,1);
				update(x1,y2,-1);
				update(x2,y1,-1);
				update(x2,y2,1);
		  }
	  }
	  
	}
   

return 0 ;
}
