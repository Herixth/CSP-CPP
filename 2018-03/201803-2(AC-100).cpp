#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*利用二维数组ball进行数据操作
ball[0][i]中记录第i个小球所在的坐标
ball[1][i]中记录第i个小球当前的运动方向：规定1为向右，0为向左
读取完数据之后即可对每一个时刻的小球运动进行模拟
在每一个时刻t0，即0<=t0<t,每一个小球都会运动，对每一个小球进行操作

进行的操作为两步：
1、遍历每一个小球，判断该小球在该时刻该位置的方向需不需要改变：
需要改变方向的情况有两种： 
	a)该小球到达左边界且方向向左，即ball[0][i] == 0 && ball[1][i] == 0
	b)该小球与另一个小球位置重合，即ball[0][i] == ball[0][j]
		注意：两个球重合这种情况不会出现在边界点，且重合的小球方向必定相反
遍历ball数组，将满足a,b条件的小球方向改变，即取反
2、移动每一个小球，因为当前状态下的小球的方向都是合理的
所以对于第i个小球，ball[1][i] == 1时，ball[0][i]++;ball[1][i] == 0时，ball[0][i]--

在对所有时刻进行处理之后对ball[0][i]进行输出*/ 

void Change_direction(vector< vector<int> > &ball, int L) {
	for (int i = 0; i < ball[0].size(); i ++) {
		if ((ball[0][i] == L && ball[1][i]) || (!ball[0][i] && !ball[1][i])) 
			ball[1][i] = !ball[1][i];
		for (int j = i + 1; j < ball[0].size(); j ++) 
			if (ball[0][i] == ball[0][j]) {
				swap(ball[1][i], ball[1][j]);
				break;
			}
	}
}

void Move(vector< vector<int> > &ball, int L) {
	Change_direction(ball, L);         // 在每次移动前将需要改变方向的操作进行 
	for (int i = 0; i < ball[0].size(); i ++) 
		ball[0][i] += ball[1][i] ? 1 : -1;
}

int main() {
	vector< vector<int> > ball(2);
	int n, L, t, loc;
	cin >> n >> L >> t;
	
	for (int i = 0; i < n; i ++) {
		cin >> loc;
		ball[0].push_back(loc);
		ball[1].push_back(1);
	}
	
	for (int time = 0; time < t; time ++)
		Move(ball, L);
	
	for (int i = 0; i < n; i ++)
		i ? cout << " " << ball[0][i] : cout << ball[0][i];
	cout << endl; 
	return 0;
}
