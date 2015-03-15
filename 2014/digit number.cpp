#include <iostream>
using namespace std;
const int N=11;
static int d[N];
void deal(int n)
{if (n<0) return;
 else
 if (n==0)  d[0]++;
 else
 while (n)
 {d[n%10]++;
  n=n/10;
 }
}

int main()
{int a,b,digit,i;
 cout<<"Please input two integers:";
 cin>>a>>b;
 if (a==0 && b==0) return 0;
 if (a>b) {int temp=a;a=b;b=temp;}
 //for (i=0;i<11;i++)
//     d[i]=0;
 for (i=a;i<=b;i++)
     deal(i);
 cout<<"Please input a digit(0~9):";
 cin>>digit;
 cout<<"The number of digit "<<digit<<" is:"<<d[digit]<<"\n";
}
