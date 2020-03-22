//Main idea: 해당 지점까지 벽을 몇개나 부셔야 하는지 메모이제이션 한다.
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int Map[100][100];
int cache[100][100];
pair<int, int> arr[4] = { {1,0},{-1,0},{0,1},{0,-1} };

void Input() {
	cin >> M >> N;
	memset(cache, -1, sizeof(cache));
	char tmp;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> tmp;
			Map[y][x] = tmp - '0';
		}
	}
}

void Dfs(int y, int x, int br) {
	int& ret = cache[y][x];//이전에 해당 지점 까지 가는데 부쉈던 벽의 최소 갯수
	if (ret != -1 && ret <= br)
		return;
	ret = br;//이번에 온 경로가 벽을 덜 부수고 온 경우 -> 이 것 때문에 재방문 처리 안해도 됨
	if (y == N - 1 && x == M - 1) 
		return;

	for (pair<int, int>& a : arr) {
		int ny = y + a.first;
		int nx = x + a.second;
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		Dfs(ny, nx, br + Map[ny][nx]);
	}
}

void AlgoSpot() {
	Input();
	Dfs(0, 0, 0);
	cout << cache[N - 1][M - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	AlgoSpot();
}
