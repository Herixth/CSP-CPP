#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*���ö�ά����ball�������ݲ���
ball[0][i]�м�¼��i��С�����ڵ�����
ball[1][i]�м�¼��i��С��ǰ���˶����򣺹涨1Ϊ���ң�0Ϊ����
��ȡ������֮�󼴿ɶ�ÿһ��ʱ�̵�С���˶�����ģ��
��ÿһ��ʱ��t0����0<=t0<t,ÿһ��С�򶼻��˶�����ÿһ��С����в���

���еĲ���Ϊ������
1������ÿһ��С���жϸ�С���ڸ�ʱ�̸�λ�õķ����費��Ҫ�ı䣺
��Ҫ�ı䷽�����������֣� 
	a)��С�򵽴���߽��ҷ������󣬼�ball[0][i] == 0 && ball[1][i] == 0
	b)��С������һ��С��λ���غϣ���ball[0][i] == ball[0][j]
		ע�⣺�������غ����������������ڱ߽�㣬���غϵ�С����ض��෴
����ball���飬������a,b������С����ı䣬��ȡ��
2���ƶ�ÿһ��С����Ϊ��ǰ״̬�µ�С��ķ����Ǻ����
���Զ��ڵ�i��С��ball[1][i] == 1ʱ��ball[0][i]++;ball[1][i] == 0ʱ��ball[0][i]--

�ڶ�����ʱ�̽��д���֮���ball[0][i]�������*/ 

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
	Change_direction(ball, L);         // ��ÿ���ƶ�ǰ����Ҫ�ı䷽��Ĳ������� 
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
