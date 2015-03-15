// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "CandyMaking.cpp"
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
#include <unistd.h>
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

int n;
class CandyMaking
{
        public:
		double solve(double x,vector<int> a, vector <int > b)
		{
		  double  sum = 0;
		  for(int i = 0 ;i < n ;i ++)
			  sum += fabs(x*a[i] - b[i]);
		  return sum;
		}
        double findSuitableDensity(vector <int> a, vector <int>b)
        {
           n = a.size();
		   double  ans = 1e9;
		   for(int i = 0 ;i < n;i ++)
		   {
		       double temp = b[i]*1.0/a[i];
			   ans = min(solve(temp,a,b),ans);
		   }
		   return ans;
		}
        

};
