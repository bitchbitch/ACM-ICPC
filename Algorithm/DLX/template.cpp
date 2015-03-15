/* ***********************************************
Author        :kuangbin
Created Time  :2014/5/25 22:55:25
File Name     :E:\2014ACM\专题学习\DLX\HUST1017.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int maxnode = 100010;
const int MaxM = 1010;
const int MaxN = 1010;
struct DLX
{
    int n,m,size;
    int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode]; // COL 代表快速找到这列  ROW 快速找到这行
    int H[MaxN], S[MaxM];
    int ansd, ans[MaxN];
    void init(int _n,int _m)
    {
        n = _n;
        m = _m;
        for(int i = 0;i <= m;i++)
        {
            S[i] = 0; // S 代表的是每一列的颜色
            U[i] = D[i] = i;
            L[i] = i-1;
            R[i] = i+1;
		}
        R[m] = 0; L[0] = m;
        size = m;
        for(int i = 1;i <= n;i++)
            H[i] = -1;  //  H[i]  代表第I 行的头
    }
    void Link(int r,int c)
    {
        ++S[Col[++size]=c];
        Row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0)H[r] = L[size] = R[size] = size;
        else
        {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size; // 插入到  H[r] 的右边
        }
    }
    void remove(int c) //列为单位，横向
    {
        L[R[c]] = L[c]; R[L[c]] = R[c];
        for(int i = D[c];i != c;i = D[i])
            for(int j = R[i];j != i;j = R[j])
            {
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --S[Col[j]];
            }//删除一列，k行
    }
    void resume(int c)
    {
        L[R[c]] = R[L[c]] = c;
        for(int i = U[c];i != c;i = U[i])
            for(int j = L[i];j != i;j = L[j])
                ++S[Col[U[D[j]]=D[U[j]]=j]];
    }
    //d为递归深度
    bool Dance(int d)
    {
        if(R[0] == 0)
        {
            ansd = d;
            return true;
        }
        int c = R[0];
        for(int i = R[0];i != 0;i = R[i])
            if(S[i] < S[c])
                c = i;
        remove(c); // 这里的C 是列节点 D[c] 代表的是这一列的第一个节点
        for(int i = D[c];i != c;i = D[i])
        {
            ans[d] = Row[i];
            for(int j = R[i]; j != i;j = R[j])remove(Col[j]);
            if(Dance(d+1))return true;
            for(int j = L[i]; j != i;j = L[j])resume(Col[j]);
        }
        resume(c);
        return false;
    }
};

DLX g;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        g.init(n,m);
        for(int i = 1;i <= n;i++)
        {
            int num,j;
            scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&j);
                g.Link(i,j);
            }
        }
        if(!g.Dance(0))printf("NO\n");
        else
        {
            printf("%d",g.ansd);
            for(int i = 0;i < g.ansd;i++)
                printf(" %d",g.ans[i]);
            printf("\n");
        }
    }
    return 0;
}
