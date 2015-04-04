#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define llu unsigned long long
const unsigned long long mod = 1000*1000*1000+7;

int T,p;
pair<int,int> a[100005];

int main() {
	freopen("input","r",stdin);
	freopen("output1","w",stdout);
	scanf("%d",&T);
	for(int cs=1;cs<=T;++cs) {
		printf("Case %d: ",cs);
		scanf("%d",&p);
		for(int i=0;i<p;++i) {
			scanf("%d%d",&a[i].first,&a[i].second);
		} sort(a, a+p);
		llu cnt = 0, ans = 0;
		llu cnt_ans = 1;
		for(int i=0;i<p;++i) {
			llu cur = a[i].second;
			cnt += cur;
			ans += cnt * cur;
		}
		for(int i=p-1;i>=0;--i) {
			llu cur = a[i].second;
			if(i == p-1) continue;
			else cnt_ans = cnt_ans * (cur + 1) % mod;
		} printf("%llu %llu\n",ans,cnt_ans);
	}
}
