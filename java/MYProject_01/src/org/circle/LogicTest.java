package org.circle;

public class LogicTest {
   public static void main(String[] args){
	    boolean a, b , c;
	    a = true ; 
	    b = false ; 
	    c = a & b ; 
	    System.out.println(c);
	    c = a|b; 
	    System.out.println(c);
	    c = a^b; 
	    System.out.println(c);
	    c = !a; 
	    System.out.println(c);
	    c = a && b ; 
	    System.out.println(c);
	    c = a || b ; 
	    System.out.println(c);
   }
}
