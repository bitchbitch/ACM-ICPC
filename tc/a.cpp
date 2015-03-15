// File Name: a.cpp
// Author: darkdream
// Created Time: 2013年12月15日 星期日 01时04分07秒

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
class TheSuttles{
	public: int getLeasetCost(vector<int> a,int b, int c)
			{
				int len = a.size();
				int min = 100000000;
				int tmin;
				for(int i = 1;i <= 100;i++)
				{
					tmin = 0 ; 
					for(int j = 0 ;j < len ;j ++)
					{
						int k;
						if(a[j] % i == 0 )
						{
							k = a[j]/i;
						}else k = a[j]/i + 1;
						tmin += k*(b + c*i);
					}
					if(tmin < min)
						min = tmin;
				}
				return min;
			}

};

int main(){
     
	return 0;
}
