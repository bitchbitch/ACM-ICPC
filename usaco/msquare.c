// File Name: msquare.c
// Author: darkdream
// Created Time: 2014年03月10日 星期一 21时01分14秒
/*
ID: dream.y1
PROG: msquare
LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
struct node{
  int a[9];
  char N;
  int step;
  int last;
}list[50000];
int hs[50000];
int A[10];
int hehe(int *a)
{
    int ths[10] ;
	memset(ths,0,sizeof(ths));
	int vhs = 0 ;
    for(int i = 1;i <= 8 ;i ++)
	{
		int tsum =0 ; 
	    for(int j = 1;j < a[i] ;j ++)
			if(!ths[j])
				tsum ++ ; 
		vhs += (tsum * A[ 8-i ]);
		ths[a[i]] = 1; 
	}
	return vhs;
}
void printans(int p)
{
   if(p == 1 )
	   return;
   printans(list[p].last);
   printf("%C",list[p].N);
}
int main(){
   freopen("msquare.in","r",stdin);
   freopen("msquare.out","w",stdout);
   memset(hs,0,sizeof(hs));
   memset(list,0,sizeof(list));
   A[0] = 0; 
   A[1] = 1; 
   for(int i = 2; i <= 8 ;i ++)
   {
     A[i] = i* A[i-1];
   }
   //freopen("/home/plac/problem/input.txt","r",stdin);
   int temp[10];

   for(int i = 1;i <= 8 ;i  ++)
   {
      scanf("%d",&temp[i]) ; 
	  list[1].a[i] = i ; 
   }
   int ans = hehe(temp);
   //printf("%d\n",ans);
   
   if(ans == 0 )
   {
	   printf("0\n\n");
       return 0 ;
   }
   hs[hehe(list[1].a)] = 1;
   list[1].step = 0; 
   int low = 1, high = 1; 
   while(low <= high )
   {
      
	  for(int i = 1;i <= 8;i ++)
		  temp[i] = list[low].a[9-i];

	  int vhs =  hehe(temp);
	  if(!hs[vhs])
	  {
		 hs[vhs] = 1; 
	     high ++ ; 
		 list[high].step = list[low].step + 1;  
		 for(int i = 1;i <= 8;i ++)
		 {
		  list[high].a[i] = temp[i];
		 }
		 list[high].N = 'A'; 
		 list[high].last = low;
		 if(vhs == ans)
		 {
		   printf("%d\n",list[high].step);
		   printans(high);
		   break;
		 }
	  }  // first
	  
	  temp[1] = list[low].a[4];
	  temp[8] = list[low].a[5];
	  for(int i= 2;i <= 4;i ++)
	  {
	    temp[i] = list[low].a[i-1];
	  }
	  for(int i= 5;i <= 7;i ++)
	  {
	    temp[i] = list[low].a[i+1];
	  }
	  vhs =  hehe(temp);
	  if(!hs[vhs])
	  {
		 hs[vhs] = 1; 
	     high ++ ; 
		 list[high].step = list[low].step + 1;  
		 for(int i = 1;i <= 8;i ++)
		 {
		  list[high].a[i] = temp[i];
		 }
		 list[high].N = 'B'; 
		 list[high].last = low;
		 if(vhs == ans)
		 {
		   printf("%d\n",list[high].step);
		   printans(high);
		   break;
		 }
		
	  }  // 2 change
	 

	  temp[1] = list[low].a[1];
	  temp[2] = list[low].a[7];
	  temp[3] = list[low].a[2];
	  temp[4] = list[low].a[4];
	  temp[5] = list[low].a[5];
	  temp[6] = list[low].a[3];
	  temp[7] = list[low].a[6];
	  temp[8] = list[low].a[8];
	  vhs =  hehe(temp);
	  if(!hs[vhs])
	  {
		 hs[vhs] = 1; 
	     high ++ ; 
		 list[high].step = list[low].step + 1;  
		 for(int i = 1;i <= 8;i ++)
		 {
		  list[high].a[i] = temp[i];
		 }
		 list[high].N = 'C'; 
		 list[high].last = low;
		 if(vhs == ans)
		 {
		   printf("%d\n",list[high].step);
		   printans(high);
		   break;
		 }
	  }
   
     low ++ ; 
   }
 printf("\n");   
return 0 ;
}
