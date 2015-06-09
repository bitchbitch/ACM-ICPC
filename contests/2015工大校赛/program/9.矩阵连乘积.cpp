#include <iostream>
using namespace std;

int p[21];
int m[20][20],s[20][20];

void matrixchain(int *p,int n)
{
    for (int i=0;i<n;i++) m[i][i]=0;
    for (int r=2;r<=n;r++)
        for (int i=0;i<=n-r;i++)
        {int j=i+r-1;
            m[i][j]=m[i+1][j]+p[i]*p[i+1]*p[j+1];
            s[i][j]=i;
            for (int k=i+1;k<j;k++)
            {int t=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
                if (t<m[i][j]) {m[i][j]=t;s[i][j]=k;}
            }
        }
}


main()
{int i,n;
    cin>>n;
    for (i=0;i<=n;i++)
        cin>>p[i];
    matrixchain(p,n);
    cout<<"The least times is:"<<m[0][n-1]<<endl;

}
