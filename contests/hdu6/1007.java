import java.math.BigInteger;
import java.util.Scanner;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
            BigInteger  b,c;
            int t,n;
            t=cin.nextInt();
			while(t--)
			{
			  BigInteger a[3000];
			  n = cin.nextInt();
			  for(int i = 1;i <= n;i ++)
			  {
			      a[i] = cin.nextBigInteger();
			  }
			  int k = n; 
			  while(--k)
			  {
			      for(int i = n-k;i <= n;i ++)
				  {
				     a[i].subtract(a[i-1]) 
				  }
			  }
			  System.out.println(a[n]);
			}
        }
    }
}
