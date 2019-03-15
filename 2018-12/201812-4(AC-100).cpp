#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

#define For_(X, B, E) for (int X = B; X < E; X ++)

const int maxn = 1e5 + 1;

struct Edge {
	int u, v;
	int dist;
	Edge (int u, int v, int dist) {
		this->u = u, this->v = v, this->dist = dist;
	}
	~Edge() { }
	
	bool operator < (const Edge& obj) {
		return this->dist < obj.dist;
	}
};

int Path[maxn];
int N, M;
int tot_cost;
vector<Edge> edges;


void init_path(int n) {
	For_(iter, 0, n + 1) {
		Path[iter] = iter;
	}
}

void readInfo() {
	int root = 0;
	scanf("%d %d %d", &N, &M, &root);
	
	For_(iter, 0, M) {
		int u = 0, v = 0, dist = 0;
		scanf("%d %d %d", &u, &v, &dist);
		edges.push_back(Edge(u, v, dist));
	}
}

int inline find_path(int v) {
	return Path[v] == v ? v : Path[v] = find_path(Path[v]);
}

bool inline judge_union(int u, int v) {
	int root_u = find_path(u);
	int root_v = find_path(v);
	if (root_v == root_u) {
		return true;
	}
	else {
		Path[root_v] = root_u;
		return false;
	}
}

void Kruskal() {
	int num = edges.size();
	int cnt = 0;
	For_(iter, 0, num) {
		if (judge_union(edges[iter].u, edges[iter].v))
			continue;
		cnt ++;
		tot_cost = edges[iter].dist;
		if (cnt >= N - 1)
			break;
	}
}

int main() {
	
	readInfo();
	
	init_path(N);
	
	sort(edges.begin(), edges.end());
	
	Kruskal();
	
	printf ("%d\n", tot_cost);
	
	return 0;
}


