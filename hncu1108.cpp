#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#define MAXN 25
using namespace std;
int i,j;
int m,n;
int ans;
int xadd[] = {1,-1,0,0};
int yadd[] = {0,0,1,-1};
char map[MAXN][MAXN];
int visit[MAXN][MAXN];
void dfs(int a,int b){
	printf("%d %d\n",a,b);
    map[a][b] = '#';	
	for(i=0;i<4;i++){
	   int xx=a+xadd[i];
	   int yy=b+yadd[i];
	   if(xx<0 || yy<0 || xx>=m || yy>=n)
		   continue;
	   if(map[xx][yy]=='.' && visit[xx][yy] ==  0){
			   visit[xx][yy] = 1; 
			   dfs(xx,yy);
	   }
	}

}
int main(){
	int q,w;
	while(cin>>n>>m){
		ans=0;
		memset(visit,0,sizeof(visit));
		for(i=0;i<m;i++){
			scanf("%s",map[i]);
			for(j=0;j<n;j++){
				if(map[i][j]=='@')
				  q=i,w=j;
			}
		}
		visit[q][w] = 1 ;
		dfs(q,w);
		cout<<ans<<endl;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				cout<<map[i][j];
			}
			cout<<endl;
		}
		int sum = 0 ; 
		for(i = 0 ;i < m;i ++)
		{
		     for(int j = 0 ;j < n ;j ++)
				 if(visit[i][j] == 1)
				 {
				  sum ++ ; 
				 }
		}
		printf("%d\n",sum);
	}
	return 0;
}
