package org.circle;

public class PrimeNumber {
   boolean isPrime(int n )
   {
	    for(int i = 2;i <= n/2 ;i ++)
	    {
	       if(n % i == 0 )
	    	   return false ;
	    }
	    return true ;
	   
   }
   void printPrime(int m ){
	   int j = 0 ; 
	   for(int i = 2;i <= m ;i ++)
	   {
		   if(isPrime(i)){
			   j ++ ;
			   if(j % 10 == 0)
			   {}
			   
		   }
		   
	   }
	   
   }
}
