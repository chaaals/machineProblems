#include <stdio.h>

int main(){
	
	int n, slowCompute = 0, fastCompute = 0, i,j;
	int userInput;
	int navigation = 0;
	
	printf("Which summation of N are you looking to compute? N = ");
	scanf("%d",&n);
	
	printf("\n**********************************************************");
	
	printf("\n1 - Slow Compute\n");
	printf("2 - Fast Compute\n");
	
	for(i = 0; i < n; i++){
		slowCompute += n;
	}
	fastCompute = (n*(n+1))/2;

	
	printf("1 - %d", slowCompute);
	printf("\n");
	printf("2 - %d", fastCompute);
	printf("\n");
	if(slowCompute != fastCompute){
		printf("They are not equal");
	}else{
		printf("They are equal");
	}
	
	return 0;
}
