// File Name: spin.c
// Author: darkdream
// Created Time: 2014年03月03日 星期一 19时14分20秒
/*
ID: dream.y1
PROG: spin
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

struct node{
  int x, y ; 
}map[6][100];
int num[100];
int speed[100];
int yes(int x, int p )
{
   if(p == 6 )
	   return 1 ;
   
   for(int j = 1;j <= num[p]; j ++)
   {
	   if(map[p][j].y < map[p][j].x )
	   {
		  if(!(x >map[p][j].y && x < map[p][j].x))
			 return  yes(x,p+1);

	   }else {
	      if(x >= map[p][j].x  && x <= map[p][j].y)
			return   yes(x,p+1);
	   } 
   }
  // printf(" %d %d\n",x,p);
   return 0 ;
	
}
void test()
{
			for(int j = 1;j <= 5;j ++)
			{	for(int s = 1; s <= num[j] ;s ++)
				{
				   printf("%d %d** ",map[j][s].x,map[j][s].y );

				}
				printf("\n");
			
			}

}
int ifok()
{
    for(int i = 0 ;i <= 360;i ++)
		if(yes(i,1))
		{  
			return 1; 
		}
	return 0 ; 

}
void dospeed()
{
  for(int i =1;i <= 5;i ++)
  {
     for(int j =1;j <= num[i];j ++)
	 {
	    map[i][j].x  = (map[i][j].x + speed[i] ) % 360 ;
	    map[i][j].y  = (map[i][j].y + speed[i] ) % 360 ;
	 }
  }
}
void init()
{
  memset(map,0,sizeof(map));
  memset(num,0,sizeof(num));
  memset(speed,0,sizeof(speed));
}
int main(){
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
  init();
  for(int i = 1;i <= 5;i ++)
  {
      scanf("%d %d",&speed[i],&num[i]);
	  for(int j  =1 ;j  <= num[i] ;j ++)
		{
		  scanf("%d %d",&map[i][j].x,&map[i][j].y);
		  map[i][j].y = (map[i][j].x + map[i][j].y) % 360;
		}
  }
  //int ok = 0;
  int time = 0 ;
  
  if(ifok())
  {
     printf("0\n");
	 return 0;
  }
  while(1)
  {
	//if(time == 0)
	//	test();
    time ++ ; 
    dospeed();
	if(ifok())
		break;
	if(time > 400)
		break;
  }
  if(time <= 400)
	  printf("%d\n",time);
  else printf("none\n"); 
return 0 ;
}	
