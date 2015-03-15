#include <iostream>
using namespace std;

int main()
{int i,j,k,m,n,x,a[10000];
 char b[10000];
 cout<<"Please input an integer: ";
 cin>>b;
 for (n=0,i=0;b[i]!='\0';i++)
   {n++;a[i]=b[i]-48;}
 cout<<"please input the number of bits to delete: ";
 cin>>k;
 i=0;m=0;x=0;
 cout<<"The bits to be deleted: "; 
 while (x<k && m==0)
  {i=i+1;
   if (a[i-1]<a[i])
     {cout<<a[i-1]<<" ";
	  for (j=i-1;j<n-x-1;j++)
	     a[j]=a[j+1];
	  x++;
	  i=0; 
	 }
   if (i==n-x-1) m=1;
  }
  if (x<k) 
     for (i=n-k;i<=n-x-1;i++) cout<<a[i]<<" ";
  cout<<endl;
  cout<<"The max number after deletion: ";
  for (i=0;i<n-k;i++)
    cout<<a[i];
  
}
