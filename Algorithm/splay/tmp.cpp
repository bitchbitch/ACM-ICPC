
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

#define Key_value ch[ch[root][1]][0]
const int MAXN = 1000010;
int pre[MAXN],ch[MAXN][2],key[MAXN];
int root,tot1;

int s[MAXN],tot2;//内存池

void NewNode(int &r,int father,int k)
{
	if(tot2) r = s[tot2--];//取的时候是tot2--,存的时候就要是++tot2
	else r = ++tot1;//这个必须是++tot1
	pre[r] = father;
	ch[r][0] = ch[r][1] = 0;
	key[r] = k;
}
//初始化
void Init()
{
	root = tot1 = tot2 = 0;
	ch[root][0] = ch[root][1] = key[root] = pre[root] = 0;
}
//旋转,0为左旋，1为右旋
void Rotate(int x,int kind)
{
	int y = pre[x];
	ch[y][!kind] = ch[x][kind];
	pre[ch[x][kind]] = y;
	if(pre[y])
		ch[pre[y]][ch[pre[y]][1]==y] = x;
	pre[x] = pre[y];
	ch[x][kind] = y;
	pre[y] = x;
}
//Splay调整，将r结点调整到goal下面
void Splay(int r,int goal)
{
	while(pre[r] != goal)
	{
		if(pre[pre[r]]==goal)
			Rotate(r,ch[pre[r]][0] ==r);
		else
		{
			int y = pre[r];
			int kind = ch[pre[y]][0]==y;
			if(ch[y][kind] == r)
			{
				Rotate(r,!kind);
				Rotate(r,kind);
			}
			else
			{
				Rotate(y,kind);
				Rotate(r,kind);
			}
		}
	}
	if(goal == 0)root = r;
}
int ABS(int a)
{
  if(a < 0)
	  return -a;
  return a;
}
const int INF = 0x3f3f3f3f;
int Insert(int k)//插入一个值为k的结点(有重复插入)
{
	int r = root;
	if(r == 0)
	{
		NewNode(root,0,k);
		return k ;
	}
    int mi = INF;
	while(1)
	{
	    mi = min(mi,ABS(key[r] -k));
	    //printf("%d\n",ABS(key[r] -k));
		if(!ch[r][key[r]<k])
			break;
		r = ch[r][key[r]<k];
	}
	NewNode(ch[r][key[r]<k],r,k);
	Splay(ch[r][key[r]<k],0);//转到根部
	//printf("%d\n",mi);
	return mi ;
}
//找前驱
int Get_pre(int r)
{
	if(ch[r][0] == 0)return -1;//不存在
	r = ch[r][0];
	while(ch[r][1])r = ch[r][1];
	return r;
}
//找后继
int Get_next(int r)
{
	if(ch[r][1] == 0)return -1;
	r = ch[r][1];
	while(ch[r][0])r = ch[r][0];
	return r;
}

int main()
{
	//printf("%d\n",INF);
	//   freopen("in","r",stdin);
	// freopen("out1","w",stdout);
	int n;
	scanf("%d",&n);	
	Init();
	int a;
	int ans = 0;
	for(int i = 0;i < n;i++)
	{
		if(scanf("%d",&a) == EOF)  a= 0;
		ans += Insert(a);
	}
	printf("%d\n",ans);
	return 0;
}
