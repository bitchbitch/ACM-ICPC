#include <iostream>
#include <string.h>
using namespace std;
const int N=3000;

struct node{
	 int color;
}t1[N],t2[N],t3[N];
int ans;
char str1[N],str2[N];

char* build_tree(char *str,node t[N],int r){
	 int i;
	  char *j=str;

	   t[r].color=-1;
	    for (i=0;i<4;i++)
			  if (*j=='e'){
				     t[4*r+i+1].color=0;
					    j++;
						  }
		  else if (*j=='f'){
			     t[4*r+i+1].color=1;
				    j++;
					  }
		  else{
			     t[4*r+i+1].color=-1;
				    j=build_tree(j+1,t,4*r+i+1);
					  }
		 return j;
}

void unions(node r1,node r2,int ord){
	 if (r1.color==1 || r2.color==1)
		   t3[ord].color=1;
	  else if (r1.color==0 && r2.color==0){
		    t3[ord].color=0;
			 }
	   else{
		     t3[ord].color=-1;
			   for (int i=1;i<=4;i++)
				      unions(t1[4*ord+i],t2[4*ord+i],4*ord+i);
			    }
}

void count(node r,int ord,int sum){
	 if (r.color==1)
		   ans+=sum;
	  else if (r.color==-1){
		    for (int i=1;i<=4;i++)
				   count(t3[4*ord+i],4*ord+i,sum/4);
			 }
}

int main(){
	 int t;

	  cin>>t;
	   while (t--){
		     cin>>str1>>str2;
			   if (strlen(str1)==1)
				      t1[0].color=(str1[0]=='e')?0:1;
			     else
					    build_tree(str1+1,t1,0);
				   if (strlen(str2)==1)
					      t2[0].color=(str2[0]=='e')?0:1;
				     else
						    build_tree(str2+1,t2,0);
					   unions(t1[0],t2[0],0);
					     ans=0;
						   count(t3[0],0,1024);
						     cout<<"There are "<<ans<<" black pixels."<<endl;
							  }
	    return 0;
}

