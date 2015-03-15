#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,102400000")

#define LOCAL_TEST
int n, m;
string maze[101];
bool able[4][101][101];
// > v < ^
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool outBoard(int x, int y)
{
	if(x < 0 || x >= n) return true;
	if(y < 0 || y >= m) return true;
	return false;
}

int getID(char c, int delay)
{
	if(c == '>') return (0 + delay) % 4;
	if(c == 'v') return (1 + delay) % 4;
	if(c == '<') return (2 + delay) % 4;
	if(c == '^') return (3 + delay) % 4;
	return -1;
}

bool laserShootYou(int x, int y, int delay)
{
	for(int dir = 0; dir < 4; dir ++)
	{
		for(int i = 0; ; i++)
		{
			int nx = x + dx[dir] * i;
			int ny = y + dy[dir] * i;
			if(outBoard(nx, ny)) break;
			if(maze[nx][ny] == '#') break;
			int id = getID(maze[nx][ny], delay);
			if(id != -1)
			{
				if(id == (dir + 2) % 4) return true;
				break;
			}
		}
	}
	return false;
}

int qx[10000001];
int qy[10000001];
int qMod[10000001];
int dist[101][101][4];

int sx, sy, tx, ty;
int now = 0, z = 0;

int MAIN()
{
	int T;
	cin >> T;
	int caseID = 0;
	while(T--)
	{
		now = 0, z = 0;
		cout << "Case #" << ++caseID << ": ";
		cin >> n >> m;
		for(int i = 0; i < n; i++)
		{
			cin >> maze[i];
			for(int j = 0; j < m; j++)
			{
				if(maze[i][j] == 'S')
					sx = i, sy = j;
				if(maze[i][j] == 'G')
					tx = i, ty = j;
			}
		}
		for(int d = 0; d < 4; d++)
			for(int i = 0; i < n; i++)
				for(int j = 0; j < m; j++)
				{
					able[d][i][j] = true;
					if(maze[i][j] == '#')
						able[d][i][j] = false;
					if(laserShootYou(i, j, d))
						able[d][i][j] = false;
				}
		memset(dist, 0xe, sizeof(dist));
		int ans = 100000000;
		if(sx == tx && sy == ty) ans = 0;
		qx[0] = sx;
		qy[0] = sy;
		qMod[0] = 0;
		dist[sx][sy][0] = 0;
		while(now <= z)
		{
			int x = qx[now];
			int y = qy[now];
			int mods = qMod[now];
			for(int f = 0; f < 4; f++)
			{
				int nx = x + dx[f];
				int ny = y + dy[f];
				if(outBoard(nx, ny)) continue;
				int nMods = (mods + 1) % 4;
				if(able[nMods][nx][ny] == false) continue;
				if(dist[nx][ny][nMods] > dist[x][y][mods] + 1)
				{
					dist[nx][ny][nMods] = dist[x][y][mods] + 1;
					z ++;
					qx[z] = nx;
					qy[z] = ny;
					qMod[z] = nMods;
					if(nx == tx && ny == ty)
						ans = min(ans, dist[nx][ny][nMods]);
				}
			}
			++ now;
		}
		if(ans >= 100000000) cout << "impossible" << endl;
		else cout << ans << endl;
	}
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
