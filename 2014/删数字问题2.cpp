#include <iostream>
using namespace std;

int main()
{int i,k,m,n,t,x,a[10000],b[10000];
 char c[10000];
 cout<<"Please input an integer: ";
 cin>>c;
 for (n=0,i=0;c[i]!='\0';i++)
   {n++;a[i]=c[i]-48;b[i]=a[i];}
 cout<<"please input the number of bits to delete: ";
 cin>>k;
 t=0;m=0;x=0;
 i=t+1; 
 while (x<k && i<=n)
  {if (t>=0 && a[t]<a[i])
     {cout<<a[t];
      a[t]=-1;
      while (t>=0 && a[t]==-1)
         t--;
      x++;      
	 }
    else t=i++;
  }
  cout<<"The bits to be deleted: ";
  for (i=0;i<n;i++)
	  if (a[i]==-1) cout<<b[i]<<" ";
  if (x<k)
	  for (i=n-1;i>=0 && x<k;i--)
	  if (a[i]!=-1) {cout<<b[i]<<" ";x++;}
  cout<<endl;
  cout<<"The max number after deletion: ";
  for (i=0,x=0;x<n-k;i++)
     if (a[i]!=-1)
       {cout<<a[i];x++;}
}
