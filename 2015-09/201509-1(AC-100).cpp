#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int n;
	scanf("%d",&n);
	int ans = 1;
	int num[1000];
	for(int i = 0; i < n; i ++)
	scanf("%d",&num[i]);
	
	for(int j = 1; j < n; j ++){
		if(num[j] == num[j - 1])
		continue;
		else
		ans ++;
	}
	
	printf("%d\n",ans);
	
	return 0;
}
