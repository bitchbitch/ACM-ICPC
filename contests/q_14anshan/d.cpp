// File Name: d.cpp
// Author: darkdream
// Created Time: 2014年10月22日 星期三 13时26分25秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long
#define maxn 51005
#define eps 1e-8
using namespace std;
double a[maxn];
int site[maxn];
double zx[maxn];
int LN;
int find(double x , int l , int r)
{

   while(l <= r )
   {
      int m = (l +  r)/2;
	  if(a[m] > x)
		  r = m - 1; 
	  else 
          l = m + 1;
   }
   return r; 
}
int main(){
    int t; 
	scanf("%d",&t);
	while(t--)
	{
        int n , k ; 
		scanf("%d %d",&n,&k);
	    for(int i = 1;i <= n;i ++)
		{
		   scanf("%lf",&a[i]);
		}
		sort(a+1,a+1+n);
		if(k >= n)
		{
			printf("0.00000000000\n");
		    continue;
		}
	    LN = n - k ;
		double sum = 0 ; 
		double lans,rans,lsum,rsum;
		lans = rans = lsum = rsum = 0 ;

		for(int i = 1;i <= LN;i ++)
		{
		    sum += a[i];  
		}
		zx[1] = sum / LN;
        site[1] = find(zx[1],1,1 + LN-1);
		for(int i = 1;i <= LN;i ++)
		{
		   double tt = fabs(zx[1] - a[i]);
		   if(a[i] <= zx[1])
		   {
		      lsum += tt;
			  lans += tt * tt; 
		   }else {
		      rsum += tt; 
			  rans += tt * tt; 
		   }
		}
		double mi = lans + rans;
		for(int i = 2;i <= k + 1;i ++)
		{
		   sum -= a[i-1];
		   sum += a[i + LN -1];
		   zx[i] = sum/LN;
		   site[i] = find(zx[i],i,i + LN -1);
           double dis = zx[i] - zx[i-1] ;
		   lsum  -= fabs(a[i-1] - zx[i-1]);
           lans  -= fabs(zx[i-1] -a[i-1]) * fabs(zx[i-1] -a[i-1]);
           lans  += lsum * dis * 2 + dis *dis * (site[i-1] - i + 1);
		   lsum += dis * (site[i-1] - i + 1);
		   for(int j = site[i-1] + 1;j <= site[i];j ++)
		   {
			    double tt = fabs(a[j] - zx[i]);
                double tt1 = fabs(a[j] - zx[i-1]);
		        lsum += tt; 
				lans += tt*tt;
				rsum -= tt1;
				rans -= tt1 * tt1;
		   }
          // printf("%lf\n",rsum);
	       rans += dis * dis *(i-1 + LN - 1 - site[i]) - rsum * dis * 2;
		   rans += fabs(zx[i] - a[i+LN-1]) * fabs(zx[i] - a[i+LN-1]) ;
		   rsum += fabs(zx[i] - a[i+LN-1]) - dis *(i-1+LN-1-site[i]);
           //printf("%lf\n",rsum);
           //printf("%lf %lf %lf %lf %lf\n",lsum,rsum,lans,rans,zx[i]);
		   if(rans + lans < mi)
			   mi = rans + lans;
		}
     printf("%.10lf\n",mi);
	    
	}
return 0;
}
