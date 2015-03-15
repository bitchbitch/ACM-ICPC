// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "TaroGrid.cpp"
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


class TaroGrid
{
        public:
        int getNumber(vector <string> grid)
        {
             int n = grid[0].size();
			 int mx = 1; 
			 int len = grid.size();
			 for(int i = 0 ;i < n ;i++)
			 {
			   int temp = grid[0][i]; 
			   int sum = 1 ; 
			   for(int j = 1;j < len ;j ++)
			   {
			     if(grid[j][i] == temp)
				 {
				    sum ++ ; 
				 }else {
				    sum = 1 ;
					temp = grid[j][i];
				 }
				 if(sum > mx)
					 mx = sum ;
			   }
			 }
		  return mx;
		}
        

};

