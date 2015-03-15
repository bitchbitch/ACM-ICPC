// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "GoodSubset.cpp"
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

vector <LL>a;
int num[105];
int n ; 
int rn; 
map <LL,LL>  mp[105];
map <LL,LL> ::iterator it;
#define M 1000000007
class GoodSubset
{
        public:
        int numberOfSubsets(int goodValue, vector <int> d)
        {
		  for(int i = 0 ;i <=100 ;i ++)
			  mp[i].clear();
		  mp[0][1] = 1;
	      n = d.size();
		  for(int i = 1 ;i <=n ;i ++)
		  {
            int t = 0 ;
		    for( it = mp[i-1].begin();it != mp[i-1].end();it++)
			{
			t ++ ; 
			  //printf("%d %lld %lld\n",i,it->first,it->second);
			   mp[i][it->first] = (mp[i][it->first] + mp[i-1][it->first])%M;
			   if(goodValue % (d[i-1]*it->first) == 0 )
				   mp[i][d[i-1]*it->first] = (it->second+mp[i][d[i-1]*it->first])%M;
			}
		//	printf("%d\n",t);
		  }
		   if(goodValue == 1)
			   mp[n][goodValue] -- ;
           return int(mp[n][goodValue]);
		}

};

