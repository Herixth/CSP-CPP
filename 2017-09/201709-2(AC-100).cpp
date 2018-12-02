#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
//	freopen("²âÊÔÊı¾İ.txt", "r", stdin);
	
	int K, N, begin, end;
	int key[1001], teacher[1001][3], re[1001], br[1001];
	scanf("%d%d",&K,&N);
	for(int i = 0; i < K; i++) key[i] = i + 1;   
	
	for(int i = 0; i < N; i++) 
	scanf("%d %d %d",&teacher[i][0],&teacher[i][1],&teacher[i][2]);
	
	// for(int i = 0; i < N; i++){
	//  printf("%d %d %d\n",teacher[i][0],teacher[i][1],teacher[i][2]);
	// }
	begin = teacher[0][1];
	for(int i = 0; i < N; i++)
	if(begin > teacher[i][1]) begin = teacher[i][1];
	
	end = teacher[0][2] + teacher[0][1];
	for(int i = 0; i < N; i++)
	if(end < teacher[i][2] + teacher[i][1]) end = teacher[i][2] + teacher[i][1];
	
	for(int i = begin; i <= end; i++){
		int p = 0;
		memset(re, 0, sizeof(re));
		memset(br, 0, sizeof(br));
		for(int j = 0; j < N; j++)
		if(teacher[j][2] + teacher[j][1] == i) re[p++] = teacher[j][0]; 

		int q = 0;
		for(int j = 0; j < N; j++)
		if(teacher[j][1] == i) br[q++] = teacher[j][0]; 
	
		
//		printf("i = %d, ",i);
//		for(int j = 0; j < p; j++) printf("re = %d ",re[j]);
//		for(int j = 0; j < q; j++) printf("br = %d ",br[j]);
//		printf("\n");
		
		for(int j = 0; j < p - 1; j++){     //give back the keys
			for(int u = j + 1; u < p; u++){
				if(re[j] > re[u]){
					int t = re[j];
					re[j] = re[u];
					re[u] = t;
				}
			}
		}
		int y = 0;
		for(int j = 0; j < K; j++)
		//   printf("key[%d] = %d, ",j,key[j]);
		if(key[j] == 0) key[j] = re[y++];
		
		//        for(int i = 0; i < K; i++) printf("%d ",key[i]);
		//     printf("\n");
		
		for(int j = q - 1; j >= 0; j--){
			for(int u = K - 1; u >= 0; u--){
			//    printf("key[%d] = %d, br[%d] = %d\n",u,key[u],j,br[j]);
				if(key[u] == br[j]){
					key[u] = 0;
					break;
				}
			}
		}
		
		//  for(int i = 0; i < K; i++) printf("%d ",key[i]);
		//     printf("\n");
		
	}
	
	for(int i = 0; i < K; i++) printf("%d ",key[i]);
	printf("\n");
	
	return 0;
}
