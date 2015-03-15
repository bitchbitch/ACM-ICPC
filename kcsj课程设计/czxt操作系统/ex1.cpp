/************************************************************
 * Author : darkdream
 * Email : darkdream1994@gmail.com 
 * Last modified : 2014-12-29 13:34
 * Filename : ex1.cpp
 * Description :
 * *********************************************************/
// experiment1.cpp : Defines the entry point for the console application.
//

#include "stdlib.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <algorithm>

using namespace std;
typedef struct PCB
{
	int name;
	int runtime;
	int runedtime;
	int state;
	int killtime;
	int waitpoint;//
	int waittime;
	struct PCB *next;
}PCB;

int timeslice=3; //时间片
PCB *runqueue=NULL; //运行队列
PCB *top=NULL,*tail=NULL,*temp;  //就绪队列
PCB *top_wait=NULL,*tail_wait=NULL; //等待队列
void add_tail(struct PCB *temp)
{
	if(tail !=NULL)
	{
		tail->next = temp;
	}else{
		tail = temp;
		top = temp;
	}
}
void add_tail_wait(struct PCB *temp)
{
	if(tail_wait !=NULL)
	{
		tail_wait->next = temp;
	}else{
		tail_wait = temp;
		top_wait = temp;
	}
}
#define NUM 2
int main(int argc, char* argv[])
{

	int i;
	srand(time(NULL));
	for(i=0;i<NUM;i++)
	{
		temp=new PCB;
		temp->name=i;
		temp->runtime=rand()%20+1;
		temp->runedtime=0;
		temp->next=NULL;
		temp->killtime=0;
		temp->waitpoint=rand()%temp->runtime+1;
		temp->waittime=rand()%20+1;
		if(i==0) {top=temp; tail=temp;} 
		else{
			tail->next=temp;
			tail=temp;
		}
		printf("process name %d, runtime=%d, runedtime=%d,killtime=%d, waitpoint=%d,waittime=%d\n"
				,tail->name,tail->runtime,tail->runedtime,tail->killtime,tail->waitpoint,tail->waittime); 
	}


	int now = 0 ;
	int last =0 ; 
	while(runqueue==NULL||top==NULL||top_wait==NULL)
	{
		printf("系统时间为：%d:\n",now);
	/*	if (top_wait!=NULL)
		{
			temp=top_wait;
			while(temp!=NULL)
			{
				if(now-temp->waitpoint == temp->waittime)
				{
					swap(*temp,*top_wait);
					swap(temp->next,top_wait->next);
					add_tail(top_wait);
					top_wait = top_wait->next;
				}
				temp=temp->next;
			}
		}//  从阻塞队列中删除一个节点 把它加入到 就绪队列里面
*/
		if (runqueue==NULL && top != NULL)//进行调度
		{
			runqueue = top;
			top = top->next;
			if(top == NULL)
				tail = NULL; //将等待队列中的进程加入到运行队列
			printf("进程 %d 已经开始运行  进程状态为:\n",runqueue->name);
			printf("process name %d, runtime=%d, runedtime=%d,killtime=%d, waitpoint=%d,waittime=%d\n\n"
					,top->name,top->runtime,top->runedtime,top->killtime,top->waitpoint,top->waittime); 
		}else
		{
			if(runqueue->runtime == runqueue->runedtime)
			{
				printf("进程 %d 已经运行结束  进程状态为:\n",runqueue->name);
				printf("process name %d, runtime=%d, runedtime=%d,killtime=%d, waitpoint=%d,waittime=%d\n\n"
						,runqueue->name,runqueue->runtime,runqueue->runedtime,runqueue->killtime,runqueue->waitpoint,runqueue->waittime); 
				last = now;
				runqueue = NULL;
			}else{
				if(now == runqueue->waitpoint)
				{
					add_tail_wait(runqueue);
					printf("运行中的进程 %d 已经到等待时间 加入阻塞队列  进程状态为:\n",runqueue->name); 
					{
						printf("process name %d, runtime=%d, runedtime=%d,killtime=%d, waitpoint=%d,waittime=%d\n\n"
								,runqueue->name,runqueue->runtime,runqueue->runedtime,runqueue->killtime,runqueue->waitpoint,runqueue->waittime); 
						last = now;
					}
					runqueue = NULL;
				}
				if(now - last == timeslice)
				{
					printf("进程 %d 被杀死  进程状态为:\n",runqueue->name);
					runqueue->killtime +=1;
					printf("process name %d, runtime=%d, runedtime=%d,killtime=%d, waitpoint=%d,waittime=%d\n\n"
							,runqueue->name,runqueue->runtime,runqueue->runedtime,runqueue->killtime,runqueue->waitpoint,runqueue->waittime); 
					last = now; 

					add_tail(runqueue);

					runqueue = NULL;
					tail->next = runqueue;
				}else{
					printf("进程 %d 正在运行 进程状态为:\n",runqueue->name);
					printf("process name %d, runtime=%d, runedtime=%d,killtime=%d, waitpoint=%d,waittime=%d\n\n"
							,runqueue->name,runqueue->runtime,runqueue->runedtime,runqueue->killtime,runqueue->waitpoint,runqueue->waittime); 
				}
			}	
		}
		if(top != NULL)
		{

		}//将等待队列中的加入到阻塞队列中
		if (runqueue==NULL)//进行调度
		{
			if(top == NULL && top_wait == NULL)
			{
				printf("所有进程运行结束.");
				break;
			}
			if(top == NULL)
			{
				printf("所有进程都在阻塞队列中,没有可运行的进程");
			}else{
				top = top->next;
				if(top == NULL)
					tail = NULL; //将等待队列中的进程加入到运行队列
				runqueue = top;
				printf("进程 %d 已经开始运行  进程状态为:\n",runqueue->name);
				printf("process name %d, runtime=%d, runedtime=%d,killtime=%d, waitpoint=%d,waittime=%d\n\n"
						,runqueue->name,tail->runtime,tail->runedtime,tail->killtime,tail->waitpoint,tail->waittime); 
			}
		}
		sleep(1);
		now +=1;
		runqueue->runedtime +=1; 
	}
	printf("Hello World!\n");
	return 0;
}

