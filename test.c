#include <stdio.h>
#include <time.h>
int main(){
	time_t t; 	
	struct tm *timeinfo;
	time(&t);
	timeinfo = localtime(&t);
	printf("%s",asctime(timeinfo));
	return 0 ; 
}
