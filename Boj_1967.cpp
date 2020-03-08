//Main idea: 트리의 지름 알고리즘
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<pair<int,int>>> tree;
vector<int> cache;
int V;

void input() {
    cin >> V;
    tree.resize(V + 1);
    cache.resize(V + 1, -1);
    for (int i = 0; i < V - 1; i++) {
        int a, b, far;
        cin >> a >> b >> far;
        tree[a].push_back({ b,far });
        tree[b].push_back({ a,far });
    }
}

void dfs(int a) {
    for (pair<int, int> tmp : tree[a]) {
        int& ret = cache[tmp.first];
        if (ret == -1) {//탐색 안한 곳
            ret = cache[a] + tmp.second;
            dfs(tmp.first);
        }
    }
}

int run() {//임의의 점에서 가장 먼 점 a를 찾고 a에서 가장 먼 점 b를 찾아 a->b의 거리를 반환
    cache[1] = 0;
    dfs(1);
    int far = 0;
    int dist = 0;
    for (int i = 1; i <= V; i++) {
        if (dist < cache[i]) {
            dist = cache[i];
            far = i;
        }
    }
    cache.clear();
    cache.resize(V + 1, -1);
    cache[far] = 0;
    dfs(far);
    dist = 0;
    for (int tmp : cache)
        dist = max(dist, tmp);
    return dist;
}

void TreeDiameter(){
    input();
    cout << run();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    TreeDiameter();
}
