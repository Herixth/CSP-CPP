#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	int n;
	scanf("%d", &n);
	int record[1000][2] = {0};
	int num[1000];
	for(int i = 0; i < n; i ++)
	scanf("%d", &num[i]);
	
	int count = 0;
	for(int u = 0; u < n; u ++){
		int flag = 0;
		for(int h = 0; h < count; h ++)
		if(num[u] == record[h][0]){
			record[h][1] ++;
			flag = 1;
			break;
		}	
		if(flag) continue;
		
		record[count ++][0] = num[u];
	}
	
//	for(int i = 0; i < count; i ++)
//	printf("%d ",record[i][0]);
//	printf("\n");
	
	
	for(int t = 0; t < count - 1; t ++)
	for(int f = t + 1; f < count; f ++)
	if(record[t][1] < record[f][1]){
		record[t][1] = record[t][1] ^ record[f][1];
		record[f][1] = record[t][1] ^ record[f][1];
		record[t][1] = record[t][1] ^ record[f][1];
		record[t][0] = record[t][0] ^ record[f][0];
		record[f][0] = record[t][0] ^ record[f][0];
		record[t][0] = record[t][0] ^ record[f][0];
	}
	
//	for(int i = 0; i < count; i ++)
//	printf("%d %d\n", record[i][0], record[i][1]);
//	printf("\n");
	
	int fan = 0;
	for(int s = 0; s < count; ){
		int d = s;
		for(d = s; d < count; d ++){
			if(record[d][1] != record[s][1])
			break;
		}
		for(int x = s; x < d - 1; x ++)
		for(int y = x + 1; y < d; y ++)
		if(record[x][0] > record[y][0]){
			 record[x][0] = record[y][0] ^ record[x][0];
			 record[y][0] = record[y][0] ^ record[x][0];
			 record[x][0] = record[y][0] ^ record[x][0]; 
			 record[x][1] = record[y][1] ^ record[x][1];
			 record[y][1] = record[y][1] ^ record[x][1];
			 record[x][1] = record[y][1] ^ record[x][1];
		} 
		s = d;
	}
	
	for(int j = 0; j < count; j ++)
	printf("%d %d\n",record[j][0],record[j][1] + 1);
	
	return 0;
}
