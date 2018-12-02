#include<stdio.h>

int main(){
	int cash;
	scanf("%d",&cash);
	
	int a, b, c, d, x = 0;
	a = cash / 50;
	x = x + a * 7;
	
	cash = cash % 50;
	
	c = cash / 30;
	x = x + c * 4;
	cash = cash % 30;
	
	b = cash / 10;
	x = x + b * 1;
	printf("%d\n",x);
	return 0;
} 
