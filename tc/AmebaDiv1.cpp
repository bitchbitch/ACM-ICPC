// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "AmebaDiv1.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
 struct node{
		    long long x; int y ; 
 }a[300];

int cmp1(const void *a ,const void *b)
{
    if((*(node*) a).x == (*(node *)b).x)
      return(*(node*) a).y - (*(node *)b).y;
    return(*(node*) a).x - (*(node *)b).x;
}
class AmebaDiv1
{
        public:
        int count(vector <int> X)
        {
           int n = X.size();
		   for(int i = 0 ;i < n;i ++)
		   {
			  long long ans = X[i];
		      for(int j = 0 ;j < n ;j ++)
				  if(X[j] == ans)
					  ans *= 2 ;
			  a[i].x = ans;
			  a[i].y = X[i] ; 
		   }
		   qsort(a,n,sizeof(node),cmp1);
		   node b[1000];
		   int bnum = 1; 
		   b[1].x = a[0].x;
		   b[1].y = a[0].y;
		   for(int i =1; i< n;i ++)
		   {
		      if(a[i].x != a[i-1].x || a[i].y != a[i-1].y  )
		        {
				  bnum ++ ; 
				  b[bnum].x = a[i].x;
				  b[bnum].y = a[i].y;
				}		   
		   }
		   int sum = 0 ;
		   for(int i = 1;i <= bnum;i ++)
			   for(int j = 0 ; j < n ;j ++)
			   {
				 if(i >= 2 && b[i].x == b[i-1].x)
					 break;
			     if(b[i].x == X[j])
				 {
				  sum ++ ;
				  break;;
				 }
			   }
		   int tsum = 0 ;
		   /*sort(c+1,c+cnum+1);
           if(cnum >= 1)
		   {
			  tsum = 1; 
		      for(int i = 2;i <= cnum ;i ++)
				  if(c[i] != c[i-1])
					  tsum ++ ; 
		   }
		   for(int i = 1;i <= cnum;i ++)
			   printf("%lld ",c[i]);
		   printf("\n");
		   printf("%d\n",tsum);*/
		   return bnum-sum + tsum ;
		}
        

};

