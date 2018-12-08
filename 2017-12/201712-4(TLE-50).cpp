/*************************************************************************
    > File Name: Path.cpp
    > Author: Herixth
    > Mail: herixth@gmail.com 
 ************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

const int maxn = 501, maxm = 1e5 + 1;


struct Edge {
    int target;
    int dist;
    int rec_;
    bool sign; // 0 big 1 small
    bool vis;
    
    Edge(int target = 0, int dist = 0, bool sign = false,
            int rec_ = -1, bool vis = false):
        target(target), dist(dist), sign(sign), rec_(rec_),
        vis(vis) {  }
};

struct Vertex {
    int num;
    bool in_sign;
    int dist;
    int dist_buff;

    Vertex(int num = 0, bool s = false, int d = 0, int b = 0):
        num(num), in_sign(s), dist(d), dist_buff(b) { }
};

vector<Edge> adj_list[maxn];

int N, M; //vertex and edge
int ans = 1e6 + 10;

void readData() {
    scanf("%d%d", &N, &M);
    for (int inc = 0; inc < M; inc ++) {
        int sign = 0;
        int verF = 0, verS = 0, dist = 0;
        scanf("%d%d%d%d", &sign, &verF, &verS, &dist);
        verF --, verS --;
        adj_list[verF].push_back(Edge(verS, dist, sign, adj_list[verS].size()));
        adj_list[verS].push_back(Edge(verF, dist, sign, adj_list[verF].size() - 1));
    }
}



void BFS() {
    queue<Vertex> Q;
    Q.push(Vertex());
    while(!Q.empty()) {
        Vertex curr_ver = Q.front(); Q.pop();

        vector<Edge>::iterator iter = adj_list[curr_ver.num].begin();
        for (; iter != adj_list[curr_ver.num].end(); iter ++) {
            if (loc_value(curr_ver) && midValue[(*iter).target] < loc_value(curr_ver))
                continue;
            // if ((*iter).vis) continue;
            Vertex next_ver;
            // make sign
            (*iter).vis = true; adj_list[(*iter).target][(*iter).rec_].vis = true;
            next_ver.num = (*iter).target;
            next_ver.dist = curr_ver.dist, next_ver.dist_buff = curr_ver.dist_buff;
            if ((*iter).sign - curr_ver.in_sign) {
                if ((*iter).sign) { // 0 -> 1
                    next_ver.in_sign = true;
                    next_ver.dist_buff = (*iter).dist;
                }
                else {  // 1 -> 0
                    next_ver.in_sign = false;
                    next_ver.dist += pow(next_ver.dist_buff, 2);
                    next_ver.dist += (*iter).dist;
                    next_ver.dist_buff = 0;
                    ;
                }
            } 
            else {
                if ((*iter).sign) {
                    next_ver.in_sign = true;
                    next_ver.dist_buff += (*iter).dist;
                }
                else {
                    next_ver.in_sign = false;
                    next_ver.dist += (*iter).dist;
                }
            }
            if (next_ver.dist + pow(next_ver.dist_buff, 2) > ans)
                continue;
            if (next_ver.num == N - 1) {
                ans = min(ans, int(next_ver.dist + pow(next_ver.dist_buff, 2)));
            }
            else {
                if (loc_value(next_ver) < ans) {
                    Q.push(next_ver);
                    midValue[next_ver.num] = loc_value(next_ver);
                }
            }
        }
    }
}

int main() {

    readData();
    
    BFS();

    printf("%d\n", ans);

    return 0;
}
