#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int student[1001];
	for(int i = 0; i < n; i ++)
	student[i] = i + 1;
	
	int loc = 0;
	int num = 1;
	while(1){
		int count = 0;
		for(int i = 0; i < n; i ++)
		if(student[i]) count ++;
		if(count == 1) break;
		
		if(!student[loc]){
			loc ++;
			loc = loc % n;
			continue;
		}
		
		if(!(num % k) || num % 10 == k)
		student[loc] = 0;
		
		loc ++;
		loc = loc % n;
		num ++;
	}  
	
	for(int i = 0; i < n; i ++)
	if(student[i])
	printf("%d\n",student[i]);
	
	return 0;
}