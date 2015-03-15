#include <stdio.h>

int isi(long long int i)
{ int j = 1 , l , k = 1 , n;
  long long int sum = 1, i1 = i;
	  while (i1/10 !=0)
   {
     i1 = i1 /10;
	 j ++ ; 
   }
  for (l = 1  ; l<= j ; l++)
  {
      sum =sum*10;
  
  }
  if((sum+i) %i == 0)
	  return 1;
  else 
	  return 0;
}
int main()
{
  long long int i ;
  for (i=1 ; i<= 42600000; i ++)
	  if (isi(i))
	  	  printf("%lld,",i);

      
  return 0;

}


