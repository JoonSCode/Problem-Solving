//Main idea: dfs처럼 도는 것이 아닌 방향을 유지하고 후진 하는 것
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
#include <stack>

using namespace std;

int N, M;
int answer = 0;
vector<vector<int>> room;
pair<int, int> order[4] = { {-1,0},{0,1},{1,0},{0,-1} };

void Dfs(int r, int c, int idx) {
	int& ret = room[r][c];
	if (ret == 0) {
		ret = 2;
		answer++;
	}
	for(int i = 0; i< 4; i++){
		if (idx == 0)
			idx = 3;
		else
			idx--;

		pair<int, int>& a = order[idx];
		int nr = r + a.first;
		int nc = c + a.second;
		
		if (room[nr][nc] == 0) {
			Dfs(nr, nc, idx);
			return;
		}
	}
	int nr = r - order[idx].first;
	int nc = c - order[idx].second;
	if (room[nr][nc] == 1)
		return;
	Dfs(nr, nc, idx);
}

void Test() {
	cin >> N >> M;
	room.resize(N, vector<int>(M));
	int r, c, idx;
	cin >> r >> c >> idx;
	int tmp;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> tmp;
			room[y][x] = tmp;
		}
	}
	Dfs(r, c, idx);
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Test();
}
