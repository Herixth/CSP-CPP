#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int ans = 0;
	int n;
	int store[1000];
	scanf("%d",&n);
	for(int i = 0; i < n; i ++)
	scanf("%d",&store[i]);
	
	ans = abs(store[0] - store[1]);
	for(int u = 0; u < n - 1; u ++)
	for(int h = u + 1; h < n; h ++)
	if(abs(store[u] - store[h]) < ans)
	ans = abs(store[u] - store[h]);
	
	printf("%d\n",ans);
	
	return 0;
}
