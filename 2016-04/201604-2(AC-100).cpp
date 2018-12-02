#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
//	freopen("≤‚ ‘.txt", "r", stdin);
	char canvas[16][10], block[4][4], sym[4][4], same[4][4];
	int record[4];
	memset(record, 0, sizeof(record));
	int n, row_up, row_do,col_fr, col_ba, r, c, length, high;
	for(r = 0; r < 15; r++){
		for(c = 0; c < 10; c++){
			scanf("%c ",&canvas[r][c]);
		}
	}
	for(r = 0; r < 4; r++){
		for(c = 0; c < 4; c++){
			scanf("%c ",&block[r][c]);
		}
	}
	scanf("%d",&n);
	
	int f = 0, j;
	for(c = 0; c < 4; c++){             //ø®∑∂Œß 
		for(r = 0; r < 4; r++){
			if(block[r][c] == '1'){
				j = c;
				f = 1;
				break;
			}
		}
		if(f == 1) break;
	}
	col_fr = j;	
	
	f = 0;
	for(c = 3; c >= 0; c--){             //ø®∑∂Œß 
		for(r = 0; r < 4; r++){
			if(block[r][c] == '1'){
				j = c;
				f = 1;
				break;
			}
		}
		if(f == 1)break;
	}
	col_ba = j;
	
	f = 0;
	for(r = 0; r < 4; r++){             //ø®∑∂Œß 
		for(c = 0; c < 4; c++){
			if(block[r][c] == '1'){
				j = r;
				f = 1;
				break;
			}
		}
		if(f == 1)break;
	}
	row_up = j;
	
	f = 0;
	for(r = 3; r >= 0; r--){             //ø®∑∂Œß 
		for(c = 0; c < 4; c++){
			if(block[r][c] == '1'){
				j = r;
				f = 1;
				break;
			}
		}
		if(f == 1)break;
	}
	row_do = j;
	
	length = col_ba - col_fr + 1;   //À„≥ˆ◊‹øÌ∂»
	high = row_do - row_up + 1; //À„≥ˆ∏ﬂ∂» 
    
	for(c = col_fr; c <= col_ba; c++){
		for(r = row_do; r >= row_up; r--){
			if(block[r][c] == '1'){
				record[c - col_fr] = r - row_up;
				break;
			}
		}
	} 
	int min = 0, max = 0;
	for(int i = 0; i < length - 1; i++){
	    if(record[i] < record[i + 1]){
	    	min = record[i];
		}else{
			min = record[i + 1];
		}
	}
	for(int i = 0; i < length - 1; i++){
	    if(record[i] > record[i + 1]){
	    	max = record[i];
		}else{
			max = record[i + 1];
		}
	}
	for(int i = 0; i < length; i++) record[i] = record[i] - min;
	
	for(c = 0; c < length; c++){                 //ºÚªØ 
		for(r = 0; r < high; r++){
			if(r == record[c]){
				sym[r][c] = '1';
				continue;
			}
			sym[r][c] = '0';
		}
	}
	
	for(int i = 0; i < 10; i++) canvas[15][i] = '1';
	int stop = 0, count = 0, mid;
	int down = n + col_fr - 1; 
	for( ; r < 16; ){
		for(int l = 0; l < length; l++){
			mid = record[l] + count;
			if(canvas[mid][down + l] == '1'){
				stop = 1;
				break;
			}
		}
		if(stop == 1) break;
		count++;
	}
	
	if(length == 1){
		count = count + record[0] - 1;
	}else{
		count = count + max - min - 1;
	}
	
	for(int i = row_up; i <= row_do; i++){
		for(int e = col_fr; e <= col_ba; e++){
			same[i - row_up][e - col_fr] = block[i][e];
		}
	}
	
	int p = high - 1;
	for(r = count; r >= count - high + 1; r--){
		for(int i = 0; i < length; i++){
			if(same[p][i] == '1'){
				canvas[r][down + i] = '1';
			}
		}
		p--;
	}
	
	for(r = 0; r < 15; r++){
		for(c = 0; c < 10; c++){
			printf("%c ",canvas[r][c]);
		}
		printf("\n");
	}
	
	return 0;
}
