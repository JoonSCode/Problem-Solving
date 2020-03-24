//Main idea: 그래프 순회
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int ans = 0;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int idx) {
	ans++;
	visited[idx] = true;
	vector<int>& ret = adj[idx];
	for (const int& a : ret) {
		if (!visited[a])
			dfs(a);
	}
}

void Line() {
	int N, K, a,b;
	cin >> N >> K;
	adj.resize(N + 1);
	visited.resize(N + 1, false);
	while (K--) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	cout << ans-1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Line();
}
