// File Name: ttwo.c
// Author: darkdream
// Created Time: 2013年12月13日 星期五 10时32分17秒
/*
ID: dream.y1
PROG: ttwo
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int hs[100][100][5] ;
int map[20][20];
int xadd[6] = {-1,0,1,0};
int yadd[6] = {0,1,0,-1};
struct node{
  int x, y ,z; 
}cow,far;
void next(struct node &a)
{
   int tx = a.x + xadd[a.z];
   int ty = a.y + yadd[a.z];
   if(map[tx][ty])
   {
     a.x = tx;
	 a.y = ty;
   }else {
     a.z = (a.z+1)%4;
   }
}
int main(){
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	char str[100];
	memset(map,0,sizeof(map));
	int t = 0;
	while(scanf("%s",str) != EOF)
	{
	  t++;
	  int len = strlen(str);
	  for(int i = 0 ;i < len ;i ++)
	  {
	    if(str[i] !='*')
		{
		  map[t][i+1] = 1; 
		}
		if(str[i] == 'F')
		{
		  far.x = t ; 
		  far.y = i+1;
		  far.z = 0 ;
		}
		if(str[i] == 'C')
		{
		  cow.x = t ; 
		  cow.y = i+1;
		  cow.z = 0 ;
		}
	  }
	 
	}
	int ok = 0 ; 
	for(int i =0 ;i<= 20000;i ++)
	{
	  if(cow.x == far.x && far.y == cow.y)
	  {
	      printf("%d\n",i);
		  return 0;
	  }
	  next(cow);
	  next(far);
	//  printf("%d %d***%d %d\n",cow.x,cow.y,far.x,far.y);
	}
	printf("0\n");
	
return 0 ;
}
