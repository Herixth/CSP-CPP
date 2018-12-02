#include<stdio.h>
#include<math.h>
#include<string.h>

int main(){
	int a[1001], de[1000], dee[999];
	int n, ans = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",&a[i]);
	for(int i = 0; i < n - 1; i++){
		if(a[i] > a[i + 1]){
			de[i] = 1;
		}else{
			de[i] = -1;
		}
	}
	for(int i = 0; i < n - 2; i++){
		dee[i] = de[i] - de[i + 1];
		if(dee[i] != 0) ans++;
	}
	printf("%d\n",ans);
}
