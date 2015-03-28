#include<limits>
#include<queue>
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
 
#define LL long long
#define eps 1e-8
#define pi acos(-1)
#define INF 0x7fffffff
#define delta 0.98 //模拟退火递增变量
using namespace std;
map<LL,int>mp;
//map<int,int>mp;
vector<int>v;
int main(){
	freopen("input","r",stdin);
	freopen("output.bl","w",stdout);
    int n,k;
    while (~scanf("%d",&n)){
        mp.clear();
        LL ans=1;
        v.push_back(0);
        while(n--){
            scanf("%d",&k);
            if (k==2) printf("%lld\n",ans);
            else{
                LL s;
                scanf("%lld",&s);
                int t=v.size();
                for (int i=0;i<t;i++)
                    if (mp[v[i]+s]==0 && (v[i]+s)>=ans) {
                        mp[v[i]+s]=1;
                        v.push_back(v[i]+s);
                    }
                    while (mp[ans])
                        ans++;
            }
        }
    }
    return 0;
}
