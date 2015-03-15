//  Memory   Time
//  1347K     0MS
//   by : Snarl_jsb
//   2014-11-01-10.11
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<climits>
#include<cmath>
#define N 1000010
#define LL long long
using namespace std;

struct Node
{
    LL num;
    LL cost;
};
Node no[110];
LL a[110];
struct Hehe
{
    LL num;
    LL cost;
};
Hehe he[250];

bool cmp(Node a,Node b)
{
    return a.cost<b.cost;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    freopen("C:\\Users\\ASUS\\Desktop\\cin.cpp","r",stdin);
//    freopen("C:\\Users\\ASUS\\Desktop\\cout.cpp","w",stdout);
    LL type;
    LL base=1;
    LL ans=0;
    cin>>type;
    for(LL i=1;i<=type;++i)
    {
        cin>>no[i].num>>no[i].cost;
    }
    sort(no+1,no+1+type,cmp);
    LL t;
    cin>>t;
    for(LL i=1;i<=t;++i)
    {
        cin>>a[i];
    }
    LL sum=0;
    int j=0;
    long long mm=0;

    for(LL i=1;i<type;++i)
    {
        sum+=no[i].num*no[i].cost*(j+1);
        mm+=no[i].num;
        while(j<t&&mm>=a[j])
        {
            sum+=(mm-a[j++])*no[i].cost;
        }
    }
    cout<<sum<<endl;
    return 0;
}


