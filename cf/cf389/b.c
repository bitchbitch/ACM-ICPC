// File Name: b.c
// Author: darkdream
// Created Time: 2014年02月03日 星期一 23时52分06秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int map[200][200];
int n ; 
int ok2 = 1; 
void dfs(int x, int y )
{
     if(map[x+1][y] == 1 && map[x+2][y] == 1 && map[x+1][y-1] && map[x+1][y+1])
	 {
	    map[x][y] = map[x+1][y] = map[x+2][y] = map[x+1][y-1]=map[x+1][y+1] = 0 ; 
	 }else ok2 = 0 ; 

}
char str[1000];
int main(){
	scanf("%d",&n);
	memset(map,0,sizeof(map));
	for(int i =1 ;i <= n;i ++)
	{
	  scanf("%s",str);
	  for(int j= 0 ;j < n ;j ++)
	  {
	    if(str[j] == '#')
			map[i][j+1] = 1;
	  }
	}
	for(int i =1;i <= n ;i ++ )
		for(int j=1 ; j <= n;j ++)
		{
		  if(map[i][j])
			  dfs(i,j);
		}
	if(ok2== 0)
		printf("NO\n");
	else {
	  printf("YES\n");
	}
return 0 ;
}
