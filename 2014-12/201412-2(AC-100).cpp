#include<stdio.h>
#include<string.h>

int main(){
	int n;
	scanf("%d", &n);
	int zz[500][500];
	for(int i = 0; i < n; i ++)
	for(int j = 0; j < n; j ++)
	scanf("%d",&zz[i][j]);
	int mo[500][500] = {0};
	
	int row = 0, col = 0;
	int count = 0;
	printf("%d ", zz[row][col]);
	while(count < n * n - 1){
		if(col + 1 < n && !mo[row][col + 1]){
			printf("%d ", zz[row][++ col]);
			count ++;
			mo[row][col] = 1;
		}
		
		while(row + 1 < n && col - 1 >= 0 && !mo[row + 1][col - 1]){
			printf("%d ", zz[++ row][-- col]);
			count ++;
			mo[row][col] = 1;
		}
				
		if(row + 1 < n && !mo[row + 1][col]){
			printf("%d ", zz[++ row][col]);
			count ++;
			mo[row][col] = 1;
		}
		
		while(row - 1 >= 0 && col + 1 < n && !mo[row - 1][col + 1]){
			printf("%d ", zz[-- row][++ col]);
			count ++;
			mo[row][col] = 1;
		}
		
	}
	
	printf("\n");
	
	return 0;
}
