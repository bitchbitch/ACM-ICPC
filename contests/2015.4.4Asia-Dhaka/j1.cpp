#include<map>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<bitset>
#include<climits>
#include<list>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef unsigned long long ll;
const ll mod=1000000007;
struct Box
{
	ll val,num;
	bool operator <(Box one)const
	{
		return val<one.val;
	}
}box[int(1e5)+10];
int main()
{
	freopen("input","r",stdin);
	freopen("output1","w",stdout);
	int T,cs=0;
	cin>>T;
	while(T--)
	{
		int p;
		cin>>p;
		for(int i=0;i<p;i++)
			cin>>box[i].val>>box[i].num;
		sort(box,box+p);
		ll ans1=0,sum=0,ans2=1;
		for(int i=0;i<p;i++)
		{
			sum+=box[i].num;
			ans1+=sum*box[i].num;
			if(i!=p-1)
				ans2=(ans2*(box[i].num+1))%mod;
		}
		cout<<"Case "<<++cs<<": "<<ans1<<" "<<ans2<<endl;
	}
}
