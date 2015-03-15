#include <iostream>
using namespace std;
int main()
{int n,i,j;
 long k,m[100000];
 cout<<"please input n:";
 cin>>n;
 m[1]=1;
 k=1;i=1;
 while (i<n)
 {k++;
  for (j=1;j<=i;j++)
  {if (k==2*m[j]+1 || k==5*m[j]-1)
    {i++;m[i]=k;
     break;
	}
  }
 }
 cout<<"m["<<n<<"]="<<m[n]<<endl;
}
