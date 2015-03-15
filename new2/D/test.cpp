//挖掘机_Coder_zha学习之路
#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<cctype>
using namespace std;
int main()
{
  freopen("in.txt","r",stdin);

	string s;
	int a[105];
	while(cin>>s)
	{
		int len=s.length();
		for(int i=0;i<len;i++)
		{
			a[i]=s[i]-48;
		}
		int num=a[0];
		for(int i=1;i<len;i++)
		{
			if(num%17==0) num=a[i];
			else num=num*10+a[i];
		}
		num=num%17;
		if(num!=0) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
