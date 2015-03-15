// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "WinterAndMandarins.cpp"
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
#include <climits>
#include <cstdlib>
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

int a[100];
int cmp(const void * a ,const void *b)
{
  return *(int *)a  -*(int *)b; 
}
class WinterAndMandarins
{
        public:
        int getNumber(vector <int> bags, int K)
        {
          int len = bags.size();
		  for(int i = 0 ;i < len ;i ++)
		   a[i] = bags[i];
		  qsort(a,len,sizeof(int),cmp);
		 /* for(int i = 0 ;i < len ;i ++ )
			  printf("%d ",a[i]);
		  printf("\n");*/
		  int min = INT_MAX;
		  for(int i = 0 ;i + K -1 < len ;i ++)
			  if(a[i+K-1]- a[i] < min)
				  min = a[i+K-1] - a[i];
          return min;
		}

};

