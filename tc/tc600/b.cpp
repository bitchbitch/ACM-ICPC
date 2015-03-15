/************************************************************
 * Author        : darkdream
 * Email         : darkdream1994@gmail.com 
 * Last modified : 2013-12-15 02:13
 * Filename      : b.cpp
 * Description   :
 * *********************************************************/
// File Name: b.cpp
// Author: darkdream
// Created Time: 2013年12月15日 星期日 01时31分47秒

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

using namespace std;
int ans[100];
int f[100];
class ORSolitaireDiv2
{
  public:
	  int getMinimum(vector<int> a ,int b)
	  {
	     int n = a.size();
		 int max = 1 << n;
		 int reans = 100;
		 for(int i = 0 ;i < max ;i ++)
		 {
		    memset(ans,0,sizeof(ans));
			int k = i;
			int p = -1;
			int r = 0;
			while(k)
			{
			  p++;
			  if(i % 2 == 1)
			  {
			    ans[p] = 1;
				r++;
			  }else ans[p] = 0;
			}
			int temp = 0 ;
			int max = 0;
			int ok = 0;
			for(int i = 0 ;i < n ;i ++)
			{
			 if(!ans[i])
			 {
			   temp = temp ^ a[i];
			   if(temp == b)
				   ok = 1;
			 }
				 
			}
			for(int i = 0 ;i < n;i ++)
			{
			 if(!ans[i])
			 {
			   temp = temp ^ a[i];
			   if(temp == b)
				   ok = 1;
			 }
				 
			}
			if(!ok)
				if(r < reans)
					reans = r;

		 }
        return reans;
	  }
};
int main(){

return 0;
}
