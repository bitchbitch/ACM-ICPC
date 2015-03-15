// File Name: rect1.c
// Author: darkdream
// Created Time: 2014年02月20日 星期四 20时32分02秒
/*
ID: dream.y1
PROG: rect1
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node{
  int lx,ly,rx,ry,c;
}a[200000];
int A, B,k;
int isin(struct node temp,int  x,int y)
{
  if( x >= temp.lx && x <= temp.rx && y >= temp.ly && y <= temp.ry)
	  return 1; 
  return 0 ; 
}
int t = 1;
int isaren(int i)
{
    return (a[i].rx - a[i].lx +1) * (a[i].ry - a[i].ly +1) ; 
}
void fun0(struct node p ,struct node q)
{
   return ;
}
void fun1(struct node p,struct node q)
{
   t ++ ; 
   a[t].lx = q.lx ; 
   a[t].ly = p.ry +1; 
   a[t].rx = p.lx -1;
   a[t].ry = q.ry;
   a[t].c = q.c ;
   if(isaren(t) <= 0)
	   t--;
}
void fun2(struct node p,struct node q)
{
   t ++ ; 
   a[t].lx = p.lx ; 
   a[t].ly = p.ry +1; 
   a[t].rx = p.rx;
   a[t].ry = q.ry;
   a[t].c = q.c ;
   if(isaren(t) <= 0)
	   t--;

}
void fun3(struct node p,struct node q)
{
   t ++ ; 
   a[t].lx = p.rx +1 ; 
   a[t].ly = p.ry +1 ; 
   a[t].rx = q.rx;
   a[t].ry = q.ry;
   a[t].c = q.c ;
   if(isaren(t) <= 0)
	   t--;

}
void fun4(struct node p,struct node q)
{
   t ++ ; 
   a[t].lx = q.lx ; 
   a[t].ly = p.ly; 
   a[t].rx = p.lx-1;
   a[t].ry = p.ry;
   a[t].c = q.c ;
   if(isaren(t) <= 0)
	   t--;
}
void fun5(struct node p,struct node q)
{
   t ++ ; 
   a[t].lx = p.rx +1 ; 
   a[t].ly = p.ly; 
   a[t].rx = q.rx;
   a[t].ry = p.ry;
   a[t].c = q.c ;
   if(isaren(t) <= 0)
	   t--;

}
void fun6(struct node p,struct node q)
{
   t ++ ; 
   a[t].lx = q.lx ; 
   a[t].ly = q.ly; 
   a[t].rx = p.lx - 1;
   a[t].ry = p.ly - 1;
   a[t].c = q.c ;
   if(isaren(t) <= 0)
	   t--;

}
void fun7(struct node p,struct node q)
{
   t ++ ; 
   a[t].lx = p.lx ; 
   a[t].ly = q.ly; 
   a[t].rx = p.rx;
   a[t].ry = p.ly - 1;
   a[t].c = q.c ;
   if(isaren(t) <= 0)
	   t--;

}
void fun8(struct node p,struct node q)
{
   t ++ ; 
   a[t].lx = p.rx + 1 ; 
   a[t].ly = q.ly; 
   a[t].rx = q.rx;
   a[t].ry = p.ly -1;
   a[t].c = q.c ;
   if(isaren(t) <= 0)
	   t--;

}
int map[100][100];
int num[10000];
void figu()
{
  for(int  i = 1;i <= t+1;i ++)
  { 
	if(isaren(i) >= 1  && a[i].c)
	{
		num[a[i].c] += isaren(i);
	}
  }
  /*
  for(int i = 0 ;i <= A-1;i ++)
  { for(int j = 0 ;j <=B -1;j ++)
		  printf("%d",map[i][j]);
	 printf("\n");
  }*/
  //for(int i = 1;i  <= t;i ++)
	//  printf("%d %d %d %d %d\n",a[i].lx,a[i].ly,a[i].rx,a[i].ry,a[i].c);
  for(int i =1 ;i <= 2500; i ++)
	  if(num[i])
	  printf("%d %d\n",i,num[i]);

}
int lastjudge(node tn1,node tn2)
{
     if(tn1.lx >= tn2.lx && tn1.lx <= tn2.rx && tn1.rx >= tn2.lx && tn1.rx <= tn2.rx && tn1.ly < tn2.ly && tn1.ry > tn2.ry)
		 return 1; 
	 if(tn1.ly >= tn2.ly && tn1.ly <= tn2.ry && tn1.ry >= tn2.ly && tn1.ry <= tn2.ry && tn1.lx < tn2.lx && tn1.rx > tn2.rx)
		 return 1;
	 return 0 ; 
}
int main(){
  freopen("rect1.in","r",stdin);
  freopen("rect1.out","w",stdout);
  scanf("%d %d %d",&A,&B,&k);
  a[1].lx = a[1].ly = 0 ;
  a[1].rx = A - 1;
  a[1].ry = B  - 1;
  a[1].c = 1 ; 
  for(int i = 2 ;i <= k + 1;i ++)
  {
  //  figu();	
	t ++ ; 
    scanf("%d %d %d %d %d",&a[t].lx,&a[t].ly,&a[t].rx,&a[t].ry,&a[t].c);
	a[t].rx -= 1; 
	a[t].ry -= 1; 
	int limit = t ; 
	for(int j = 1;j < limit  ;j ++)
	{
	  struct node tn1,tn2;
	  tn1 = a[limit];
	  tn2 = a[j];
	  if(isin(tn2,tn1.lx,tn1.ly) || isin(tn2,tn1.rx,tn1.ry) || isin(tn2,tn1.lx,tn1.ry) || isin(tn2,tn1.rx,tn1.ly)||isin(tn1,tn2.lx,tn2.ly) || isin(tn1,tn2.rx,tn2.ry) || isin(tn1,tn2.lx,tn2.ry) || isin(tn1,tn2.rx,tn2.ly)||lastjudge(tn1,tn2))
	  {
	    a[j].lx = a[j].ly = a[j].rx = a[j].ry = -1; 
		a[j].c = 0 ; 
        int hs[10];
	    memset(hs,0,sizeof(hs));
		 if(tn1.lx >= tn2.lx  && tn1.lx <= tn2.rx)
		 {
		     hs[6] = 1; 
			 hs[7] = 1; 
			 hs[8] = 1; 
		 }else tn1.lx = tn2.lx;

		 if(tn1.rx >= tn2.lx  && tn1.rx <= tn2.rx)
		 {
		     hs[1] = 1; 
			 hs[2] = 1; 
			 hs[3] = 1; 
		 }else tn1.rx = tn2.rx;
		 
		 if(tn1.ly >= tn2.ly  && tn1.ly <= tn2.ry)
		 {
		     hs[1] = 1; 
			 hs[4] = 1; 
			 hs[6] = 1; 
		 }else tn1.ly = tn2.ly;
		 
		 if(tn1.ry >= tn2.ly  && tn1.ry <= tn2.ry)
		 {
		     hs[3] = 1; 
			 hs[5] = 1; 
			 hs[8] = 1; 
		 }else tn1.ry = tn2.ry;
	//	 printf("(((((((%d %d %d %d %d\n%d %d %d %d %d))))))\n",tn1.lx,tn1.ly,tn1.rx,tn1.ry,tn1.c,tn2.lx,tn2.ly,tn2.rx,tn2.ry,tn2.c);
         void (*p[])(node,node) = {fun0,fun1,fun2,fun3,fun4,fun5,fun6,fun7,fun8};
         for(int s =1 ;s <= 8 ;s ++)
		 {
                p[s](tn1,tn2);
		 }
	  }

	  
	  }
	}
  figu();
 return 0 ;
}
