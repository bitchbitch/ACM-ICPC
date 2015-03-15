#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
int main()
{
	int i,T,N,l;
	string ss;
	map<string,int>mm;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		cin>>ss;mm[ss]=1;
		while(N--)
		{
			cin>>ss;
			l=ss.length();
			for(i=0;i<l;i++)
				if(mm[ss.substr(0,l-i)]==1)
				{
					printf("%d\n",i+1);
					break;
				}
			if(i==l)
				for(i=1;i<=l;i++)
					if(mm[ss.substr(0,i)]==0)
					{
						printf("%d\n",l-i+2);
						break;
					}
			mm[ss]=1;
		}
	}
}
