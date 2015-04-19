#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int L1, R1, L2, R2;
int memo[32][2][2][2][2];

int rec(int i, bool gt1, bool lt1, bool gt2, bool lt2) {
    int &r = memo[i+1][gt1][lt1][gt2][lt2];
    if(r != -1) return r;
    if(i == -1) return r = 0;
    r = -2;
    rep(b1, 2) {
        if(!gt1 && b1 < (L1 >> i & 1)) continue;
        bool ngt1 = gt1 || b1 > (L1 >> i & 1);
        if(!lt1 && b1 > (R1 >> i & 1)) continue;
        bool nlt1 = lt1 || b1 < (R1 >> i & 1);
        int x = 2147483647;
        rep(b2, 2) {
            if(!gt2 && b2 < (L2 >> i & 1)) continue;
            bool ngt2 = gt2 || b2 > (L2 >> i & 1);
            if(!lt2 && b2 > (R2 >> i & 1)) continue;
            bool nlt2 = lt2 || b2 < (R2 >> i & 1);
            int y = rec(i-1, ngt1, nlt1, ngt2, nlt2);
            amin(x, y | (b1 ^ b2) << i);
        }
        amax(r, x);
    }
    return r;
}

int main() {
	freopen("in","r",stdin);
    int T;
	freopen("out1","w",stdout);
    scanf("%d", &T);
    rep(ii, T) {
        scanf("%d%d%d%d", &L1, &R1, &L2, &R2);
        mset(memo, -1);
        int ans = rec(30, false, false, false, false);
        printf("Case #%d: %d\n", ii+1, ans);
    }
    return 0;
}
