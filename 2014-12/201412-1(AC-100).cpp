#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int n;
	scanf("%d", &n);
	int pp[1000];
	int record[1000][2] = {0};
	int count = 0;
	
	for(int i = 0; i < n; i ++){	
		scanf("%d", &pp[i]);
		int flag = 0;
		for(int j = 0; j < count; j ++)
		if(pp[i] == record[j][0]){
			record[j][1] ++;
			printf("%d ",record[j][1] + 1);
			flag = 1;
			break;
		}
		if(flag) continue;
		
		record[count ++][0] = pp[i];
		printf("1 ");
	}
	printf("\n");
	
	return 0;
}
