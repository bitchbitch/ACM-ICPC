// File Name: dfs2.c
// Author: darkdream
// Created Time: 2013年03月13日 星期三 15时23分07秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int map[1005][1005];
int visit[1005][1005];
int xdd[] = {1,-1,0,0};
int ydd[] = {0,0,1,-1};
int x2, y2 ,ans;
void dfs(int x, int y , int times, int site , bool h  ) 

{
	if(ans)
		return;
	if(h)
	{	
		times++;
	}
	if(times > 2)
	{
		return ;
    }
	if(times == 2 && x - x2	!= 0  && y - y2 != 0)
		return ;
	int xx ,yy  ;
   for(int i = 0 ; i < 4; i++)
   { 
     xx = x + xdd[i];
	 yy = y + ydd[i];
	 if((map[xx][yy] == 0 && visit[xx][yy] == 0) ||(xx == x2 && yy == y2))
	 {   
	     visit[xx][yy] =  1;
		 if(xx == x2 && yy == y2)
	     {
		     if(i != site && site != 5)
				 times ++;
			 if(times <= 2)
				 ans = 1;
			 return ;
         }
		  if(site == 5)
		  {  dfs(xx,yy,0,i,0);
		     visit[xx][yy] = 0 ;
		  }
		  else
		  {
		    if(i == site)
              { dfs(xx,yy,times,i,0) ;
			    visit[xx][yy] = 0 ;
			  }
		    else
			{   

				dfs(xx,yy,times,i,1);//关于times变的问题！！！？
			    visit[xx][yy]  = 0;
			}
		  }
	 }

     
   }

}
int main(){

   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n , m ;
   while(scanf("%d %d",&n,&m) != EOF)
   {
	 if (n == 0 && m== 0 )
		 break;
	 for(int i = 0;i <=1004 ; i ++ )
		 for(int j = 0 ; j<= 1004 ;j ++)
			 map[i][j] = -1;
	  memset(visit,0,sizeof(visit));
      for(int i = 1 ;i <= n ; i ++)
		  for(int j = 1; j <= m ; j++ )
			  scanf("%d",&map[i][j]);
	  int q;
	  scanf("%d",&q);
	  
	  while(q--)
	  {
		memset(visit,0,sizeof(visit));
		int x1,y1;
		ans = 0 ;
          scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	    if(map[x1][y1] != map[x2][y2] || map[x1][y1] == 0|| map[x1][y1] == 0)
			ans = 0;
		else
		{
		  visit[x1][y1] = 1;
		   dfs(x1,y1,0,5,0);
		}
		if(ans == 0)
			printf("NO\n");
		else
			printf("YES\n");
	  }
    
   }
  
return 0 ;
}
