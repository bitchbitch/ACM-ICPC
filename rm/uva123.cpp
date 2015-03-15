// File Name: uva123.cpp
// Author: darkdream
// Created Time: 2013年04月25日 星期四 19时21分46秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>

using namespace std;
struct card
{
	char v,s;
};
struct node
{
	struct card cards[54];
	int su;
	struct node  *next ,*last;
};
void find( struct node *head)
{
	struct node *temp = head;
	struct node *p ;
	int ok = 0;
	while(temp != NULL)
	{

		if(temp->last != NULL && temp->last->last != NULL && temp->last->last->last != NULL)
		{
			p = temp->last->last->last;
			if(temp->cards[temp->su].s == p->cards[p->su].s || temp->cards[temp->su].v == p->cards[p->su].v) 
			{ 
				//printf("******\n");
				p->su ++;
				p->cards[p->su].v = temp->cards[temp->su].v;
				p->cards[p->su].s = temp->cards[temp->su].s;
				temp->su--;
				if(temp->su == 0)
				{
					temp->last->next = temp->next;
					if(temp->next != NULL)
						temp->next->last = temp->last;
				}
				ok = 1;
				//free(p);   
				break;
			}
			//free(p);

		}

		if(temp->last != NULL)
		{   p = temp->last;
			if(temp->cards[temp->su].s == p->cards[p->su].s ||temp ->cards[temp->su].v == p->cards[p->su].v)
			{ 
				//printf("#####\n");
				p->su ++;
				p->cards[p->su].v = temp->cards[temp->su].v;
				p->cards[p->su].s = temp->cards[temp->su].s;
				temp->su -= 1;
				if(temp->su == 0)
				{
					p->next = temp->next;
					if(temp->next != NULL)
						temp->next->last  = temp->last;
				}
				ok = 1;
				//free(p);   
				break;
			}
			//free(p);
		}
		temp = temp -> next;

	}
	/*p = head;
	  while(p != NULL)
	  {
	  printf("%d ",p->su);
	  p = p->next;
	  }*/

	/*p = head;
	  do
	  {
	  printf("%c%c ",p->cards[p->su].v,p->cards[p->su].s);
	  p = p->next;
	  }while(p ->next != NULL);
	  printf("\n");
	  struct node *q = p->last;
	  while(q != NULL)
	  {
	  printf("%c%c ",q->cards[q->su].v,q->cards[q->su].s);
	  q = q ->last;
	  }*/


	//free(p);

	//printf("\n");
	if(ok == 1)
		find(head);
	return ;

}
int main(){

	while(1)
    {   char s[100];
	    scanf("%s",s);
		if(strlen(s) == 1)
			break;
          
		struct node *head,*wei,*p,*p1;
		
		head = (node*)malloc(sizeof(node));
		head->last = NULL;

		head->next = (node*)malloc(sizeof(node));
		head->cards[1].v = s[0];
		head->cards[1].s = s[1];
		head->su = 1;
		p = head->next;
		p->last = head;
        
		for(int i = 2;i <= 52;i++ )
		{
			scanf("%s",s);
			p->su = 1;
			p->cards[1].v = s[0];
			p->cards[1].s = s[1];
			p1 = p;	
			p->next = (node*)malloc(sizeof(node));
			p = p->next;
			p->last = p1;
		}
		/*p = head;
		  while(p !=NULL)
		  {
		  printf("%c%c \n",p->cards[1].s,p->cards[1].v);
		  p = p->next;
		  }*/
		find(head);
		p = head;
		int sum = 0;
		int k = 0;
		int num[55];

		do
		{
			num[++k] = p->su;
			p = p->next;
		}while(p->next != NULL);
		if(k >1 )
		{	
			printf("%d piles remaining:",k);
			for(int i = 1;i <= k ; i++)
				printf(" %d",num[i]);
			printf("\n");
		}
		else
		{
			printf("1 pile remaining: %d\n",num[1]);
		}
	}
	return 0;

}
