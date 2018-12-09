#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;

#define CLEAR(X) memset(X, 0, sizeof(X))
#define MARK cout << "mark" << endl 
#define FILE_READ(X) freopen(X, "r", stdin)
#define FILE_WRITE(X) freopen(X, "w", stdout)
#define TXT ((string(__FILE__).erase(string(__FILE__).find_last_of('.')) + ".txt").c_str())
#define FOR_INC(X, BEGIN, END) for (int X = BEGIN; X < END; X ++)
#define FOR_DEC(X, BEGIN, END) for (int X = BEGIN; X >= END; X --)
#define DBG(x) cout << "debug: " << __FUNCTION__ << " () @ " << __TIMESTAMP__ << "\n" \
                << "       " << __FILE__ << " L" << __LINE__ << "\n" \
                << "       " << #x " = " << (x) << endl
typedef long long LL;

const int INF = 0X0FFFFFFF;
const int maxn = 4e5 + 10;
int N, M;
/*  -*- Dijkstra算法 o(mlogn) -*-   */
struct Edge {
    int from, to, dist;
    Edge(int f = 0, int t = 0, int d = 0):
        from(f), to(t), dist(d) { }
    ~Edge() { }
};

struct HeapNode {
    int dist, u;
    bool operator < (const HeapNode &rhs) const {
        return dist > rhs.dist;
    }
};

struct Dijkstra {
    int n, m;
    vector<int> G[maxn]; 
    vector<Edge> edges;
    bool done[maxn];
    int dist[maxn];
    int pre[maxn];

    void init(int n) {
        this->n = n;
        for (int inc = 0; inc < n; inc ++) {
            G[inc].clear();
        }
        edges.clear();
    }

    void AddEdge(int from, int to, int dist) {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m - 1);
    }

    void dijkstra(int s) {
        priority_queue<HeapNode> Q;
        for (int inc = 0; inc < n; inc ++) dist[inc] = INF;
        dist[s] = 0;
        memset(done, 0, sizeof(done));
        Q.push((HeapNode){ 0, s });
        while (!Q.empty()) {
            HeapNode x = Q.top(); Q.pop();
            int u = x.u;
            if (done[u]) continue;
            done[u] = true;
            for (int inc = 0; inc < G[u].size(); inc ++) {
                Edge &e = edges[G[u][inc]];
                if (dist[e.to] > max(dist[u] , e.dist)) {
                    dist[e.to] = max(dist[u], e.dist);
                    pre[e.to] = G[u][inc];
                    Q.push((HeapNode){ dist[e.to], e.to });
                }
            }
        }
    }
};
//打印路径  S起点   node终点

/*  -*- Dijkstra算法 o(mlogn) -*-   */

Dijkstra dij;

void readData() {
    scanf("%d%d", &N, &M);
    dij.n = N;
    for (int inc = 0; inc < M; inc ++) {
        int from = 0, to = 0, levels = 0;
        scanf("%d%d%d", &from, &to, &levels);
        from--, to--;
        dij.AddEdge(from, to, levels);
        dij.AddEdge(to, from, levels);
    }
}

int main() {
    FILE_READ(TXT);
    readData();
    dij.dijkstra(0);

    printf("%d\n", dij.dist[dij.n - 1]);

    return 0;
};