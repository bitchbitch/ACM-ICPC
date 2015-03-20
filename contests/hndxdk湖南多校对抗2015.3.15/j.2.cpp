#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 1e6;
const int INF = 1e8;
const int MOD = 1e9 + 7;
char str[maxn + 100], name[65];
int dp[maxn + 100], dir[65], num[maxn + 100];
void init()
{
    int cnt = 0;
    for(int i = 0; i < 26; i++)
        name[cnt++] = 'a'+i;
    for(int i = 0; i < 26; i++)
        name[cnt++] = 'A'+i;
    for(int i = 0; i < 10; i++)
        name[cnt++] = '0'+i;
}
int main()
{
   // freopen("1534.in", "r", stdin);
   // freopen("1534.out", "w", stdout);
    init();
    int t, s, cnt, cnt2, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%s", &k, str);
        int len = strlen(str);
        memset(dir, -1, sizeof(dir));
        for(int i = len-1; i > -1; i--)
        {
            s = INF;
            cnt = cnt2 = 0;
            for(int j = 0; j < k; j++)
                if(dir[j] >= 0)
                {
                    if(s > dp[dir[j]])
                    {
                        s = dp[dir[j]];
                        cnt2 = num[dir[j]];
                    }
                    else if(s == dp[dir[j]])
                    {
                        cnt2 += num[dir[j]];
                        cnt2 %= MOD;
                    }
                }
                else
                {
                    s = 0;
                    cnt++;
                }
            if(s)
                num[i] = cnt2;
            else
                num[i] = cnt;
            dp[i] = s+1;
            if(str[i] <= '9')
                dir[str[i]-'0'+52]=i;
            else if(str[i] <= 'Z')
                dir[str[i]-'A'+26]=i;
            else
                dir[str[i]-'a']=i;
        }
		for(int i = 0 ;i < len ;i ++)
			printf("%d ",dp[i]);
		printf("\n");
		for(int i = 0 ;i < len ;i ++)
			printf("%d ",num[i]);
		printf("\n");
        int ans = INF;
        cnt = cnt2 = 0;
        for(int i = 0; i < k; i++)
            if(dir[i] >= 0)
            {
                if(ans > dp[dir[i]])
                {
                    ans = dp[dir[i]];
                    cnt2 = num[dir[i]];
                }
                else if(ans == dp[dir[i]])
                {
                    cnt2 += num[dir[i]];
                    cnt2 %= MOD;
                }
            }
            else
            {
                ans = 0;
                cnt++;
            }
//        for(int i = 0; i < k; i++)
//            cout << dir[i] << " ";
//        cout << endl;
//        for(int i = 0; i < len; i++)
//            cout << dp[i] << " ";
//        cout << endl;
//        for(int i = 0; i < len; i++)
//            cout << num[i] << " ";
//        cout << endl;
        if(ans)
            printf("%d %d\n", ans+1, cnt2);
        else
            printf("%d %d\n", ans+1, cnt);
    }
    return 0;
}
