#include<iostream>
#include<stdio.h>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define maxn 200010
int a[maxn];
int space[maxn];
int main()
{
    int n,m,s;
    int temp;
    int first,second;
    while(scanf("%d %d %d",&n,&m,&s)!=EOF)
    {
        int space_num=0;
        int candy_num=0;
        memset(a,0,sizeof(a));
        if(n==0&&m==0&&s==0)
        {
            break;
        }
        for(int i=1;i<=s;i++)
        {
            scanf("%d",&temp);
            if(a[temp]==0)
            {//�������ǹ��ĸ��ӵ���Ŀ
                candy_num++;
                a[temp]=1;
            }
        }
        for(int i=1;i<=m;i++)
        {//�ҵ���һ�����ǹ��ĸ���
            if(a[i])
            {
                first=i;
                break;
            }
        }
        for(int i=first+1;i<=m;i++)
        {//��ո��ӵ������������Ŀ
            if(a[i])
            {
                if(i-first>=2)
                {
                    space[space_num++]=i-first-1;
                }
                first=i;
            }
        }
        if(space_num<n)
        {//���ո��ӵ���������ֽƬ��Ŀʱ��ֱ��������ǹ����ӵ���Ŀ
            printf("%d\n",candy_num);
        }
        else
        {
            sort(space,space+space_num);
            int ans=candy_num;
            for(int i=0;i<=space_num-n;i++)
            {
                ans+=space[i];
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
