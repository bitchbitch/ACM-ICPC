#include<stdio.h>
#include<string.h>
#include<ctype.h>
char temp11[] = "###";
char str[257] ; 
char str1[257];
int ok = 0 ; 
void solve(int fuck)
{
  int t = 0 ; 
  int t1 = 0 ;
  int len  = strlen(str);
  int len1 = strlen(str1);
  while(t < len && t1 < len1)
  {
       if(isalpha(str[t]) && isalpha(str1[t1]))
	   {
	      if(str[t] == str1[t1]) 
		  {
		    t ++ ; 
			t1 ++ ; 
			continue;
		  }else if(isupper(str[t]) && islower(str1[t1]))
		  {
		     if(str[t] - 'A' < str1[t1] -'a')
			 {
			   puts("<");
			   return;
			 }
			 else if(str[t] - 'A' > str1[t1] -'a')
			 {
			   puts(">");
			   return;
			 }else if(fuck)
			 {
			    puts(">");
				return;
			 }
			 t ++ ; 
			 t1 ++ ;
		  }else if(isupper(str1[t1]) && islower(str[t]))
		  {
		    if(str1[t1] - 'A' < str[t] -'a')
			{
			  puts(">");
			  return;
			}else if(str1[t1] - 'A' > str[t] -'a')
			{
			  puts("<");
			  return;
			}else if(fuck)
			{
			  puts("<");
			  return;
			}
			t ++ ; 
			t1 ++;
		  }else{
		    if(str1[t1] - 'a' > str[t] - 'a')
			{
			  puts("<");
			  return;
			}else{
			  puts(">");
			  return;
			}
		  }
	   }else if(isdigit(str[t]) && !isdigit(str1[t1])) 
	   {
	      puts("<");
		  return;
	   }else if(isdigit(str1[t1]) && !isdigit(str[t])){
	      puts(">");
		  return;
	   }else{
	     char temp[257];
		 char temp1[257];
		 memset(temp,0,sizeof(temp));
		 memset(temp1,0,sizeof(temp));
		   int p = -1;
		   int flag ;
		   if(fuck)
			   flag = 1;
		   else flag = 0 ;
		   while(isdigit(str[t])) 
		   {
		     if(flag == 0 )
			 {
			   if(str[t] != '0')
			   {
			     flag = 1; 
				 p ++ ; 
				 temp[p] = str[t]; 
			   }
			 }else{
			     p ++ ;
				 temp[p] = str[t]; 
			 }
			 t ++ ;
		   }
		   p = -1;
		   if(fuck)
			   flag = 1; 
		   else flag = 0 ;
		   while(isdigit(str1[t1])) 
		   {
		     if(flag == 0 )
			 {
			   if(str1[t1] != '0')
			   {
			     flag = 1; 
				 p ++ ; 
				 temp1[p] = str1[t1]; 
			   }
			 }else{
			     p ++ ;
				 temp1[p] = str1[t1]; 
			 }
			 t1 ++ ;
		   }
		  if(!fuck)
		  {
		   int len = strlen(temp);
		   int len1 = strlen(temp1);
		   if(len1 > len)
		   {
		     puts("<");
			 return ;
		   }else if(len > len1){
		     puts(">");
			 return ;
		   }else{
		     int k = strcmp(temp,temp1);
			 if(k < 0)
			 {
			  puts("<");
			  return; 
			 }else if(k > 0 ){
			  puts(">");
			  return;
			 }
		   }
		  }else{
		     int k = strcmp(temp,temp1);
			 if(k < 0)
			 {
			  puts("<");
			  return; 
			 }else if(k > 0 ){
			  puts(">");
			  return;
			 }
		  }
	   }
  }
  if(t == len && t1 != len1)
	  puts("<");
  else if(t1 == len1 && t != len)
	  puts(">");
  else{
     ok = 1; 
  }
}
int main(){
  while(scanf("%s",str) != EOF)
  {
     if(strcmp(str,temp11) == 0 )
		 break;
	 scanf("%s",str1);
	 if(strcmp(str,str1) == 0 )
		 puts("=");
	 else {
	   ok = 0 ; 
	   solve(0);
	   if(ok)
		   solve(1);
	 }
  }
return 0;
}
