package org.circle;

public class LeapYear {
    public static void main(String[] args){
    	 int year = Integer.parseInt(args[0]);
    	 int leap; 
    	 if(year % 4 == 0 ){
    		   if(year % 400 == 0 ){ 
    			   leap = 1; 
    		   }else leap = 0 ; 
    		 
    	 }else leap = 0 ; 
    	if(leap == 1 )
    		System.out.println(year+"是润年。");
    	else System.out.println(year +"不是润年");
    }
}
