/************************************************
 * By: chenguolin                               * 
 * Date: 2013-08-26                             *
 * Address: http://blog.csdn.net/chenguolinblog *
 ***********************************************/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int64;
const int MOD = 1e9+7;
const int N = 7;

int64 n;
int64 a0 , ax , ay;
int64 b0 , bx , by;

struct Matrix{
    int64 mat[N][N];
    Matrix operator*(const Matrix &m)const{
        Matrix tmp;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                tmp.mat[i][j] = 0;
                for(int k = 0 ; k < N ; k++)
                    tmp.mat[i][j] += mat[i][k]*m.mat[k][j]%MOD;
                tmp.mat[i][j] %= MOD;
            }
        }
        return tmp;
    }
};

void init(Matrix &m){
    memset(m.mat , 0 , sizeof(m.mat));
    m.mat[0][0] = ax*bx%MOD;
    m.mat[0][1] = ax*by%MOD;
    m.mat[0][2] = bx*ay%MOD;
    m.mat[0][3] = 1; m.mat[1][1] = ax%MOD;
    m.mat[1][4] = 1; m.mat[2][2] = bx%MOD;
    m.mat[2][5] = 1; m.mat[3][3] = 1;
    m.mat[4][4] = 1; m.mat[5][5] = 1;
    m.mat[6][0] = 1; m.mat[6][6] = 1;
}

int Pow(Matrix &m){
    if(n == 0)
        return 0;
    Matrix ans;
    memset(ans.mat , 0 , sizeof(ans.mat));
    for(int i = 0 ; i < N ; i++)
        ans.mat[i][i] = 1;
    while(n){
        if(n%2)
            ans = ans*m;
        n /= 2;
        m = m*m;
    }
    int64 sum = 0;
    sum += ans.mat[N-1][0]*(a0*b0%MOD)%MOD;
    sum %= MOD;
    sum += ans.mat[N-1][1]*a0%MOD;
    sum %= MOD;
    sum += ans.mat[N-1][2]*b0%MOD;
    sum %= MOD;
    sum += ans.mat[N-1][3]*(ay*by%MOD)%MOD;
    sum %= MOD;
    sum += ans.mat[N-1][4]*ay%MOD;
    sum %= MOD;
    sum += ans.mat[N-1][5]*by%MOD;
    sum %= MOD;
    return sum%MOD;
}

int main(){
    Matrix m;
    while(scanf("%lld" , &n) != EOF){
        scanf("%lld%lld%lld" , &a0 , &ax , &ay);
        scanf("%lld%lld%lld" , &b0 , &bx , &by);
        init(m);
        printf("%d\n" , Pow(m));
    }
    return 0;
}


