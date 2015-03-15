#include <iostream>
using namespace std;
int main()
{int n,i,p2,p5;
 long m[100000];
 cout<<"please input n:";
 cin>>n;
 m[1]=1;
 p2=1;p5=1;
 for (i=2;i<=n;i++)
  {if ((2*m[p2]+1)<(5*m[p5]-1))
    {m[i]=2*m[p2]+1;p2++;}
   else
   if ((2*m[p2]+1)==(5*m[p5]-1))
    {m[i]=2*m[p2]+1;p2++;p5++;}
   else
    {m[i]=5*m[p5]-1;p5++;}
  }
 cout<<"m["<<n<<"]="<<m[n]<<endl;
}
