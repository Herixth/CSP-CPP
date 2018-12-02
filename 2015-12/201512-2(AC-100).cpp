#include<stdio.h>

int main(){
	int m, n;
	int num[31][31];                 //输入的模板数组 
	int ans[31][31];                 //用于输出的数组 
	scanf("%d %d", &n, &m);     
	      
	//数据输入 
	for(int i = 0; i < n; i ++)
	for(int j = 0; j < m; j ++){
		scanf("%d",&num[i][j]);       //输入模板数组 
		ans[i][j] = num[i][j];		  //将模板数组拷贝到输出数组 
	}
	
	//对行处理 
	for(int row = 0; row < n; row ++){    //对每一行进行检索 ，对于模板数组一行相同的超过3的在输出数组里记为0 
		int count = 1;  //用于记录相同数字的个数 
		
		for(int col = 0; col < m; count ++)   //一行中从第一列开始检索 col不自增 
		if(col + count >= m || num[row][col] != num[row][col + count]){ //当数组越界或者不相等时 
			if(count >= 3)//判断相同个数是否超过三 
			for(int h = col; h < col + count; h ++) //count大于等于三时 对ans数组中相应位置的数改为0 
			ans[row][h] = 0;
			
			col += count;   //列数向后跳count个位数 
			count = 0;
		}
	}
	
	//对列处理 
	for(int col = 0; col < m; col ++){  //对每一列检索   和上面一样 
		int count = 1;
		
		for(int row = 0; row < n; count ++)
		if(row + count >= n || num[row][col] != num[row + count][col]){
			if(count >= 3)
			for(int h = row; h < row + count; h ++)
			ans[h][col] = 0;
			
			row += count;
			count = 0;
		}		
	}
	//输出 
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++)
		printf("%d ",ans[i][j]);
		printf("\n");
	}
	
	return 0;
}
