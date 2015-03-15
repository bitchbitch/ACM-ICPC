#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long

using namespace std;
char bstr[104];
char str[104][2][104];
char str1[104][2][104];
int lstr; 
int lstr1;
void solve(char s[][2][104],int &num)
{
	 int p = 0 ;
	 if(bstr[1] == '}')
		 return;

     while(bstr[p] != '}')
	 {
		num ++ ;
	    int i ; 
		p ++ ; 
		for(i = p ;bstr[i] != ':' ;i ++) 
		{
	        s[num][0][i-p] = bstr[i];	
		}
		s[num][0][i-p] = '\0';
		p  = i+1 ; 
		for(i = p ;bstr[i] != ','&& bstr[i] != '}';i ++) 
		{
	        s[num][1][i-p] = bstr[i];
		}
		s[num][1][i-p] = '\0';
		p = i;  
	 }
}
int srt[104];
int srt1[104];
int cmp(int a,int b)
{
    if(strcmp(str[a][0],str[b][0]) < 0)
		return 1;
	return 0 ; 
}
int cmp1(int a,int b)
{
    if(strcmp(str1[a][0],str1[b][0]) < 0)
		return 1;
	return 0 ; 
}
char *push[104];
char *change[104];
char *sub[104];
int lp,lc,ls;
int solve()
{
   lp = lc = ls = 0;
   int p = 1 ; 
   for(int i = 1; i <= lstr1 ;i ++)
   {
	   int ok = 0 ;
	   int x = srt1[i];
       for(int j = p;j <= lstr; j ++)
	   {
		  int y = srt[j];
          if(strcmp(str[y][0],str1[x][0]) == 0 )
		  {
		     for(int s = p ;s < j;s ++)
			 {
			    ls ++;
				sub[ls] = str[srt[s]][0];
			 } 
			 p = j+1;
             if(strcmp(str[y][1],str1[x][1]) != 0 )
			 {
			    lc ++;
			    change[lc] = str[y][0];
			 }
			 ok = 1; 
		     break;
		  }
	   }
	   if(!ok)
	   {
	      lp ++ ;
		  push[lp] = str1[x][0];
	   }
   }
   for(;p <= lstr; p ++)
   {
     ls ++ ; 
	 sub[ls] = str[srt[p]][0];
   }
   if(lp != 0 )
   {
	 printf("+");
     for(int i = 1;i <= lp ;i ++)
		 printf(i == 1?"%s":",%s",push[i]);
	 printf("\n");
   }
   if(ls != 0 )
   {
	 printf("-");
     for(int i = 1;i <= ls ;i ++)
		 printf(i == 1?"%s":",%s",sub[i]);
     printf("\n");
   }
   if(lc != 0 )
   {
	 printf("*");
     for(int i = 1;i <= lc ;i ++)
		 printf(i == 1?"%s":",%s",change[i]);
	 printf("\n");
   }
   if(lp == 0 && ls == 0 && lc ==  0 )
   {
      return 0;    
   }
   return 1;
}
int main(){
  int n ; 
  scanf("%d",&n);
  while(n--)
  {
     lstr = 0 ; 
	 lstr1 = 0 ;
     scanf("%s",bstr);
     solve(str,lstr);
	 scanf("%s",bstr);
     solve(str1,lstr1);
     for(int i =1;i <= lstr;i ++)
		 srt[i] = i ; 
	 sort(srt+1,srt+1+lstr,cmp);
     for(int i =1;i <= lstr1;i ++)
		 srt1[i] = i ; 
	 sort(srt1+1,srt1+1+lstr1,cmp1);
	 if(!solve())
		 printf("No changes\n");
	 printf("\n");
  }
return 0;
}
