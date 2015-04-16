const int MOD = 1000000007;
 
int pow9[6];
 
int N, M;
vector<int> d;
vector<int> dtimes;
 
long dp[9*9*9*9*9][33];
 
long dp2[5001][9];
 
// how many ways to have a sum equal to m modulo 9 are there out of t digits?
long g(int t, int m)
{
    long &res = dp2[t][m];
    if (res == -1) {
        res = 0;
        if (t == 0) {
            if (m == 0) {
                res = 1;
            }
        } else {
            for (int i = 0; i <= 9; i++) {
                res += g(t - 1, (m + 9 - i) % 9);
            }
            res %= MOD;
        }
    }
    return res;
}
 
 
long f(int mask, int p)
{
    long & res = dp[mask][p];
    if (res == -1) {
        res = 0;
        if (p == M) {
            // base case
            if (mask == 0) {
                // good
                res = 1;
            }
        } else {
            // pick a sum of digits modulo 9
            for (int i = 0; i <= 8; i++) {
                // calculate the new mask:
                int mask2 = 0;
                for (int j = N-1; j >= 0; j--) {
                    int o = (mask / pow9[j]) % 9;
                    if ( (d[p] & (1<<j)) != 0 ) {
                        o = (o + i) % 9;
                    }
                    mask2 = mask2 * 9 + o;
                }
                // how many ways to have that sum of digits?
                long y = g(dtimes[p], i);
                res += (f(mask2, p+1) * y) % MOD;
            }
 
            res %= MOD;
        }
    }
    return res;
}
 
int count(int N, vector<int> d)
{
    // compress d
    map<int, int> classTimes;
    for (int x: d) {
        classTimes[x]++;
    }
    d.resize(0);
    for (auto it: classTimes) {
        d.push_back(it.first);
        dtimes.push_back(it.second);
    }
    // let's go:
    this->d = d;
    M = d.size();
    this->M = M;
    this->N = N;
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    pow9[0] = 1;
    for (int i = 1; i <= N; i++) {
        pow9[i] = 9 * pow9[i-1];
    }
    return (int)f(0,0);
}
