// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "CatsOnTheLineDiv2.cpp"
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
  int x, y; 
}cat[100];
bool cmp(node a, node b )
{
   return a.x < b.x;
}
class CatsOnTheLineDiv2
{
        public:
        string getAnswer(vector <int> p, vector <int> c, int t)
        {
           int n = p.size();
		   for(int i = 0 ; i< n;i ++ )
		   {
		      cat[i].x = p[i];
			  cat[i].y = c[i];
		   }
		   sort(cat,cat+n,cmp);
		   int s = -1e9;
		   int ok = 1;
		   for(int i = 0 ;i < n;i ++)
		   {
		
		     int k1 = max(s+1,cat[i].x-t);
			 int k2 = k1 + cat[i].y -1;
			 //printf("%d %d\n",k1,k2);
			 if(k2 - cat[i].x > t)
				 ok  = 0 ; 
             s = k2;
		   }
		   if(!ok)
			   return "Impossible";
		   else return "Possible";
		  
		}
        

};

