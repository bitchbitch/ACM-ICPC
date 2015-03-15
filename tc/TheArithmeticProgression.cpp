// File Name: TheArithmeticProgression.cpp
// Author: darkdream
// Created Time: 2013年12月12日 星期四 08时19分22秒

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

class TheArithmeticProgression{
	public:
		double minimumChange(int a, int b, int c)
		{
			if(a < b)
			{
				int temp = a; 
				a = b; 
				b = temp; 
			}
			if(a < c)
			{
				int temp = a; 
				a = c; 
				c = temp; 
			}
			if(b < c)
			{
				int temp =b; 
				b = c; 
				c = temp; 
			}
			double min = 1e98;
			double temp = (b-(a-b)-c);
			if(temp> 0 )
				min = temp;
			temp = (b+(b-c)-a);
			if(temp > 0 && temp <min)
				min = temp;
			temp = (a+c)/2.0-b;
			if(temp > 0 && temp < min)
				min = temp;
			return min;

		}

};


int main(){

	return 0;
}
