package org.circle;

public class TestSwitch {
    public static void main(String[] args){
    	  int x = 0 ; 
    	  x = Integer.parseInt(args[0]);
    	  switch(x){
    		  case 1:
    			  System.out.println("It is spring now!");break;
    		  case 2:
    			  System.out.println("It is summer now!");break;
    		  case 3:
    			  System.out.println("It is autumn now!");break;
    		  default:
    			  System.out.println("It is winter now!");
    		  
    	  }
    }
}
