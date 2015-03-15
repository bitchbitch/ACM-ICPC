// BEGIN CUT HERE
/*

*/
// END CUT HERE
#line 7 "SumOfPower.cpp"
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


class SumOfPower
{
        public:
        int findSum(vector <int> array)
        {
           int len = array.size();
		   int a[1000];
		   a[0] = array[0];
		   int sum = 0 ;
		   for(int i = 1 ;i < len ;i ++)
		   {
		       a[i] = a[i-1] + array[i];
		   }
		   for(int i =0 ;i <len ;i++)
		   {
			     for(int j = i +1 ;j <len ;j ++)
				 {
				    sum += a[j] - a[i];
				 }
			 sum += a[i];
		   }
		  return sum ;
		}
        

};
