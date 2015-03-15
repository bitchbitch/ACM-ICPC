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

int score1, score2;
long long A[2001][2001];
long long B[2001][2001];
long long mod = 1000000007;

long long a(int x, int y)
{
	if(x > score1 || y > score2) return 0;
	if(x == score1 && y == score2) return 1;
	if(x+y > 0 && y >= x) return 0;
	long long &ret = A[x][y];
	if(ret != -1) return ret;
	ret = a(x+1, y) + a(x, y+1);
	ret %= mod;
	return ret;
}

long long b(int x, int y)
{
	if(x > score1 || y > score2) return 0;
	if(x == score1 && y == score2) return 1;
	if(y != score2 && x > y) return 0;
	long long &ret = B[x][y];
	if(ret != -1) return ret;
	ret = b(x+1, y) + b(x, y+1);
	ret %= mod;
	return ret;
}


void solve()
{
	scanf("%d-%d", &score1, &score2);
	memset(A, 0xff, sizeof(A));
	memset(B, 0xff, sizeof(B));
	cout << a(0, 0) << " " << b(0, 0) << endl;
}

int MAIN()
{
	int T;
	cin >> T;
	for(int caseID = 1; caseID <= T; caseID ++)
	{
		cout << "Case #" << caseID << ": ";
		solve();
	}
	return 0;
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	//ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
