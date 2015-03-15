#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
const int INF = 0x7fffffff;
int mat[maxn][maxn];
int pre[maxn];
int minCost[maxn];
int n;
bool vis[maxn];
long long dep[maxn];
vector <int> E[maxn];
void Prim() {
    for(int i = 1; i <= n; i++) {
        minCost[i] = INF;
        vis[i] = 0;
    }
    minCost[1] = 0;
    while(true) {
        int v = -1;
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && (v == - 1 || minCost[i] < minCost[v])) v = i;
        }
        if(v == - 1) break;
        vis[v] = true;
        for(int i = 1; i <= n; i++) {
            if(!vis[i] && mat[v][i] < minCost[i]) minCost[i] = mat[pre[i] = v][i];
        }
    }
	printf("****\n");
}
void dfs(int x, int fa, long long y) {
    dep[x] = y;
    for(int i = 0; i < E[x].size(); i++) {
        int u = E[x][i];
        if(u != fa) {
            dfs(u, x, y + mat[x][u]);
        }
    }
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    bool fail = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i != j && mat[i][j] == 0) fail = 1;
            if(mat[i][j] != mat[j][i]) fail = 1;
        }
    }
    if(fail) {
        printf("NO\n");
        return 0;
    }
    Prim();
    //for(int i = 1; i <= n; i++) printf("pre[%d] = %d\n", i, pre[i]);
    for(int i = 2; i <= n; i++) {
        E[i].push_back(pre[i]);
        E[pre[i]].push_back(i);
    }
    bool succ = 1;
    for(int i = 1; i <= n && succ; i++) {
        dfs(i, 0, 0);
        for(int j = 1; j <= n; j++) if(dep[j] != mat[i][j]) succ = 0;
 
    }
    printf("%s\n", succ ? "YES" : "NO");
    return 0;
}
