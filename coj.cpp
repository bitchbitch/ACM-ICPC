#include <iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
char s[100010];
long long k;
int pos[100010];
long long sum[100010]; //sum是前n个位置的总和，会超int

bool ok(int l,int r)
{
    int mid = (l + r)/2;
    int cur_mid = pos[mid];
    int num = mid - l; //mid左边的1的个数
    long long temp = cur_mid * num - num*(num + 1)/2 - (sum[mid - 1] - sum[l - 1]); //中点左边要移动的次数
    num = r - mid;
    temp+=sum[r] - sum[mid] - num * cur_mid - num*(num + 1)/2;
    if(temp > k) return false;
    else return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s %lld",s + 1,&k);
        memset(pos,0,sizeof pos);
        sum[0] = 0;
        int len = strlen(s + 1);
        int cnt = 1;
        for(int i = 1;i <=len;i++)
        {
            if(s[i] == '1') //预处理
            {
                pos[cnt] = i;
                sum[cnt] = pos[cnt] + sum[cnt - 1];
                cnt++;
            }
        }
        cnt--; //cnt是1的个数
        int ans = 0;
        int maxn = 1;
        int i = 1;
        while(true)
        {
            if(i + maxn - 1 > cnt ) break; //区间大小比1的个数还多
            if( ok(i,i+maxn-1)) {ans = maxn;maxn++;}
            else { i++;}

        }
        printf("%d\n",ans);
    }
    return 0;
}
