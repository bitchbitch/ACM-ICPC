// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "SlimeXSlimonadeTycoon.cpp"
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

int M(int x, int y )
{
  if(x > y )
	  return x; 
  else return y ; 
}
class SlimeXSlimonadeTycoon
{
        public:
        int sell(vector <int> morning, vector <int> customers, int stale_limit)
        {
             int n = morning.size(); 
			 int sum = 0 ; 
			 for(int i = 0 ;i < n;i ++)
			 {
			     for(int j = M(i-stale_limit+1, 0); j <= i ; j ++)
				 {
				   if(customers[i] >= morning[j])
				   {
					  sum += morning[j];
					  customers[i] -= morning[j];
				      morning[j] = 0 ; 
				   }else {
				      sum += customers[i];
					  morning[j] -= customers[i];
					  customers[i] = 0; 
				   }
				 }
			 }
			 return sum ; 
		}
        

};

