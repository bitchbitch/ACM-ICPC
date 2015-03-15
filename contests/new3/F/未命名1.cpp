#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;
vector<int>luck;
bool isbad[1000*1000+10];
void maketable(int right)
{
	int i,j,t;
	for(i=0;i<=right;i++)
		luck.push_back(i);
	memset(isbad,0,sizeof(isbad));
	for(i=2;i<luck.size();i++)
	{
		t=luck[i];
		for(j=t;j<luck.size();j+=t)
			isbad[luck[j]]=1;
		for(j=0;j<luck.size();j++)
			if(isbad[luck[j]])
			{
				luck.erase(luck.begin()+j);
				j--;
			}
		if(t!=luck[i])
			i--;
	}
}
int main()
{
	int i,n,m,t,ans;
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(cin>>n>>m)
	{
		luck.clear();
		maketable(m);
		t=upper_bound(luck.begin(),luck.end(),n)-luck.begin();
		ans=luck.size()-t;
		if(luck.back()==m)
			ans--;
		cout<<ans<<endl;
	}
}
