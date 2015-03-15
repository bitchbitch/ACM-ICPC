// File Name: uva297.c
// Author: darkdream
// Created Time: 2013年05月20日 星期一 11时03分48秒

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <unistd.h>
char str[2000];
struct node
{
	char c;
	struct node * next[4];
};
struct node * newnode()
{
	struct node *p; 
	p = (node*)malloc(sizeof(node));
	for(int i = 0 ;i < 4 ;i ++)
	{
		p->next[i] = NULL;
	}
	return p;
}
int j = 1;
int sum = 0 ;
void findnode(struct node *p)
{
	struct node *temp;
	int k = 0;
	while(k < 4)
	{
		if(str[j] != 'p')
		{

			temp = newnode();
			temp->c = str[j];
			p->next[k] = temp;
			j++;
			k++;
		}
		else
		{
			temp = newnode();
			temp->c = str[j];
			p->next[k] = temp;
			j++;
			findnode(p->next[k]);
			k++;
		}

	}
	return;
}
void findalong(struct node *p,int stemp)
{
	if(p->c == 'f')
	{
		sum += stemp;
		return;
	}
	if(p->next[0] != NULL)
	for(int i =0 ; i< 4; i ++)
		findalong(p->next[i],stemp/4);

}
void finddouble (struct node *p1,struct node *p2,int stemp)
{
	if(p1->c == 'f' || p2->c == 'f')
	{
		sum += stemp;
		return;
	}
	if(p1->c == 'e' && p2->c == 'e')
		return;
	if(p1->c == 'p' && p2->c == 'p')
	{
		for(int i = 0 ;i < 4 ;i ++)
			finddouble(p1->next[i],p2->next[i],stemp/4);
		return;
	}
	if(p1->c == 'e')
		findalong(p2,stemp);
	else
		findalong(p1,stemp);
}
void print(struct node *p)
{
	if(p->next[0] != NULL)
	{  printf("%c",p->c);
		for(int i = 0 ;i < 4; i ++)
			print(p->next[i]);
	}
}
int main(){

	//freopen("/home/plac/problem/input.txt","r",stdin);
	//freopen("/home/plac/problem/output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		struct node *head1,*head2,*p;
		j = 1;
		sum = 0 ;
		scanf("%s",str);
		head1 = newnode();
		head1->c = str[0];
		if(head1->c == 'p')
			findnode(head1);
		scanf("%s",str);

		j = 1;
		head2 = newnode();
		head2->c = str[0];
		if(head2->c == 'p')	
			findnode(head2);
		 finddouble(head1,head2,1024); 	
		//print(head1);
		//print(head2);
		printf("There are %d black pixels.\n",sum);

	}
	return 0 ;
}
