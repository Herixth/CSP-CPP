#include<stdio.h>

int main(){
	int m, n;
	int num[31][31];                 //�����ģ������ 
	int ans[31][31];                 //������������� 
	scanf("%d %d", &n, &m);     
	      
	//�������� 
	for(int i = 0; i < n; i ++)
	for(int j = 0; j < m; j ++){
		scanf("%d",&num[i][j]);       //����ģ������ 
		ans[i][j] = num[i][j];		  //��ģ�����鿽����������� 
	}
	
	//���д��� 
	for(int row = 0; row < n; row ++){    //��ÿһ�н��м��� ������ģ������һ����ͬ�ĳ���3��������������Ϊ0 
		int count = 1;  //���ڼ�¼��ͬ���ֵĸ��� 
		
		for(int col = 0; col < m; count ++)   //һ���дӵ�һ�п�ʼ���� col������ 
		if(col + count >= m || num[row][col] != num[row][col + count]){ //������Խ����߲����ʱ 
			if(count >= 3)//�ж���ͬ�����Ƿ񳬹��� 
			for(int h = col; h < col + count; h ++) //count���ڵ�����ʱ ��ans��������Ӧλ�õ�����Ϊ0 
			ans[row][h] = 0;
			
			col += count;   //���������count��λ�� 
			count = 0;
		}
	}
	
	//���д��� 
	for(int col = 0; col < m; col ++){  //��ÿһ�м���   ������һ�� 
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
	//��� 
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++)
		printf("%d ",ans[i][j]);
		printf("\n");
	}
	
	return 0;
}
