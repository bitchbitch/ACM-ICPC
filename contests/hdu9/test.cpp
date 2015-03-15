/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2014-08-19 15:36
 * Filename : test.cpp
 * Description :
 * *********************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <list>
#include <vector>
#define LL long long 
#define EPS 1e-8
using namespace std;
int a[100010],s[100010],g[100010];
int main()
{
    int n,i,j;
	freopen("input.txt","r",stdin);
	freopen("output","w",stdout);
    while(~scanf("%d",&n) && n)
    {
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if (i==1)
            {
                s[i]=a[1];
                continue;
            }
            int flag=0;
            for (j=i-1;j>=1;j--)
                if (a[j] % a[i]==0)
                {
                    flag=1;
                    s[i]=a[j];
                    break;
                }
            if (!flag) s[i]=a[i];
        }
        for (i=1;i<=n;i++)
        {
            if (i==n)
            {
                g[i]=a[i];
                continue;    
            }
            int flag=0;
            for (j=i+1;j<=n;j++)
            {
                if (a[j] % a[i]==0)
                {
                    flag=1;
                    g[i]=a[j];
                    break;
                }
            }
            if (!flag) g[i]=a[i];
        }
        LL ans=0;
        for (i=1;i<=n;i++)
            ans+=s[i]*g[i];
        printf("%lld\n",ans);
    }
    return 0;
}
