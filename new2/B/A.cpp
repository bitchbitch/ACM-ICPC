#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
const int maxn = 105;

char str[maxn];
deque<char> que;
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out1","w",stdout);
    while(scanf("%s",str)!=EOF)
    {
        int len = strlen(str);
        que.clear();
        for(int i = 0;i < len;i += 2)
        que.push_front(str[i]);
        int p = 0;
        while(!que.empty())
        {
            str[p] = *que.begin();
            que.pop_front();
            p += 2;
        }
        printf("%s\n",str);
    }
    return 0;
}

