// File Name: uva10194.c
// Author: darkdream
// Created Time: 2013年03月02日 星期六 13时42分27秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
struct team{
  char name[100];
  int  goal,lgoal,gp,win,ties;

};
struct team teams[110];

int find(int i , int j )
{
    if((teams[i].win*3+teams[i].ties) > (teams[j].win*3 + teams[j].ties))
       return 0;
    if((teams[i].win*3+teams[i].ties) < (teams[j].win*3 + teams[j].ties))
        return 1;
	if(teams[i].win > teams[j].win)
		return 0;
	if(teams[i].win < teams[j].win)
		return 1;
    if((teams[i].goal - teams[i].lgoal) > (teams[j].goal - teams[j].lgoal))
		return 0 ;
    if((teams[i].goal - teams[i].lgoal) < (teams[j].goal - teams[j].lgoal))
        return 1;
	if(teams[i].goal > teams[j].goal)
		return 0;
	if(teams[i].goal < teams[j].goal)
		return 1;
	if(teams[i].gp < teams[j].gp)
		return 0;
	if(teams[i].gp > teams[j].gp)
		return 1;
    char ta[100] = {0},tb[100] ={0};
	for(int k =0 ;k < strlen(teams[i].name); k ++)
		ta[k] = toupper(teams[i].name[k]);
	for(int k =0 ;k < strlen(teams[j].name); k ++)
		tb[k] = toupper(teams[j].name[k]);
	if(strcmp(ta,tb) < 0)
		return 0;
	else
		return 1;
}

int main(){

  //  freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
  int t ;
  scanf("%d",&t);
  getchar();
  for(int h = 1; h <= t ;h ++)
   {
	memset(teams,0,sizeof(teams));
     char temp[200];
	 if(h!=1)
		 printf("\n");
	 gets(temp);
	 puts(temp);
	 int n , p , i , j , k  ;
	 scanf("%d",&n);
     getchar();
	 for(i = 1; i <= n; i++)
		 gets(teams[i].name);
	 scanf("%d",&p);
	 getchar();
	 while(p--)
	 {
	   char teamA[100] ={0},teamB[100] ={0};
	   int  ta, tb;
	   //输入
       scanf("%[^#]",teamA);
	   scanf("#%d@%d#",&ta,&tb);
	   gets(teamB);
	   for(i = 1;i <= n; i++)
		   if(strcmp(teamA,teams[i].name) == 0)
		   {
		       teams[i].gp ++;
			   teams[i].goal += ta;
			   teams[i].lgoal += tb;
			   if(ta > tb)
				teams[i].win++;
			   else if( ta == tb)
				   teams[i].ties ++;
			   break;
		   }
       for(i = 1;i <= n; i++)
		   if(strcmp(teamB,teams[i].name) == 0)
		   {
		       teams[i].gp ++;
			   teams[i].goal += tb;
			   teams[i].lgoal += ta;
			   if(tb > ta)
				teams[i].win++;
			   else if( ta == tb)
				   teams[i].ties ++;
			   break;
		   }

	 }
	   for (i = 1 ;i <= n; i++)
		   for(j =i+1 ; j<= n; j++)
		    if(find(i,j))
			{
			  struct team tp;
			  tp = teams[i];
			  teams[i] = teams[j];
			  teams[j] = tp;
			}
	for(i = 1; i <= n ;i ++)
      printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",i,teams[i].name,teams[i].win *3+teams[i].ties,teams[i].gp,teams[i].win,teams[i].ties,teams[i].gp-teams[i].win-teams[i].ties,teams[i].goal-teams[i].lgoal,teams[i].goal,teams[i].lgoal);
		
   
   }
return 0 ;
}
