#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define LL __int64
#define S scanf
#define P printf
#define min(a , b) ((a)<(b)?(a):(b))
#define max(a , b) ((a)>(b)?(a):(b))
using namespace std;
int main()
{
	freopen("cin.txt", "r", stdin);
    freopen("cout.txt", "w", stdout);
    int n,m,i,j,k,l;
	int x1,y1,x2,y2,tmp;
	int c [1610][2],h[1610][2];
    char s[41];
    while(S("%d%d\n",&n,&m)&&(n!=0||m!=0))
    {
    	memset(c,0,sizeof(c));
    	memset(h,0,sizeof(h));
		c[0][0]=1;h[0][0]=1;
    	for(i=0;i<n;i++)
    	{
    		gets(s);
    //		puts(s);
    	    for(j=0;j<m;j++)
	    	{
		        if(s[j]=='C')
		        {
		            c[c[0][0]][0]=i;
		            c[c[0][0]++][1]=j;
	  			}
	  			else
	  			    if(s[j]=='H')
	  			    {
	  			    	h[h[0][0]][0]=i;
	  			    	h[h[0][0]++][1]=j;
	  			    }
	   		}
	    }
        tmp=100000000;
   //     for(i=0;i<c[0][0];i++)
  //   		P("%dth:(%d,%d)\n",i,c[i][0],c[i][1]);
 //		P("\n");	
  //		for(i=0;i<h[0][0];i++)
//		     P("%dth:(%d,%d)\n",i,h[i][0],h[i][1]);
//	    P("\n");
   		for(i=1;i<h[0][0];i++)
   		{
		   for(j=1;j<c[0][0];j++)
   		   {
   		   		if(abs(c[j][0]-h[i][0])+abs(c[j][1]-h[i][1])<tmp)
				{
					x1=c[j][0];
					y1=c[j][1];
					x2=h[i][0];
					y2=h[i][1];
					tmp=abs(c[j][0]-h[i][0])+abs(c[j][1]-h[i][1]);
				}
				if(tmp==1)break;			  
   		   }
   		   if(tmp==1)break;
	   }
		P("%d %d %d %d\n",x2,y2,x1,y1);		    
	}
	return 0;
}

