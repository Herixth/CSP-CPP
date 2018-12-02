#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
	char num[11];
	scanf("%s", num);
	int sum = 0;
	for(int i = 0; i < strlen(num); i ++)
	sum += num[i] - '0';
	printf("%d\n",sum);
	
	return 0;
}
