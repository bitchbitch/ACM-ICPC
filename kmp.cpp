// File Name: kmp.cpp
// Author: darkdream
// Created Time: 2014年01月12日 星期日 11时50分46秒

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
int kmp(string a, string b)
{
	int pi[100];
	int lena = a.size();
	int lenb = b.size();
	int m = b.size();
	memset(pi,0,sizeof(pi));
	pi[0] = -1; 
	int k = -1 ; 
	for(int i = 1 ;i < m ; i ++)
	{
		while(k >= 0 && b[k+1] != b[i]) 
			k = pi[k];
		if(b[k+1] == b[i])
			k = k +1;
		pi[i] = k; 
	}
	int n = a.size();
	int q = -1 ; 
	for(int i = 0;i < n;i ++)
	{
		while(q >= 0 && b[q+1] != a[i])
			q = pi[q];
		if(b[q+1] == a[i])
			q = q +1;
		if(q == m-1 && i)
		{
			return 1;
		}
	}
	return 0 ; 
}
int main(){
	string a,b ; 
    cin >>a >> b ;
	if(kmp(a+b,b))
		cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}
