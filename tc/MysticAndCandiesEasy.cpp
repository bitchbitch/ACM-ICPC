/*

*/
// END CUT HERE
#line 7 "MysticAndCandiesEasy.cpp"
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


int cmp(const void *a ,const void *b)
{
  return *(int *)a - *(int *)b;
}
class MysticAndCandiesEasy
{
        public:
        int minBoxes(int C, int X, vector <int> high)
        {
          int n  = high.size();
		  int a[100];
		  for(int i = 0 ;i < n;i ++)
			a[i+1] = high[i];
		  qsort(a+1,n,sizeof(int),cmp);
		  int i = 1;
		  for(;i <= n;i ++)
		  {
		    if(C < X)
				break;
			 C -= a[i];
		  }
		  return n - i+2;

		}
        


};

