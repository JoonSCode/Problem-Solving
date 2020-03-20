//Main idea: 점과 간선의 차이 때문에 2배를 해야 인접 하지 않은 것으로 계산 할 수 있음
#include <iostream>

using namespace std;

int N;
int table[2001][2001];//-1은 방문 할 수 X 
pair<int, int> p[4] = { {1,0},{-1,0}, {0,1},{0,-1} };

void Input() {
	cin >> N;
	int x1, y1, x2, y2;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;//간격을 두배로 늘려 인접한 것 처럼 보이는 경우를 없앰
		x1 = (x1 + 500) * 2;
		y1 = (y1 + 500) * 2;
		x2 = (x2 + 500) * 2;
		y2 = (y2 + 500) * 2;

		for (int i = x1; i <= x2; i++) {
			table[y1][i] = 1;
			table[y2][i] = 1;
		}
		for (int i = y1; i <= y2; i++) {
			table[i][x1] = 1;
			table[i][x2] = 1;
		}
	}
}

void dfs(int y, int x) {
	table[y][x] = 2;
	for (pair<int, int>& a : p) {
		int ny = y + a.first;
		int nx = x + a.second;
		if (ny < 0 || nx < 0 || ny> 2000 || nx>2000)
			continue;
		if (table[ny][nx] == 1)
			dfs(ny, nx);
	}
}

void Logo() {
	Input();
	int answer = 0;
	for (int y = 0; y <= 2000; y++) {
		for (int x = 0; x <= 2000; x++) {
			if (table[y][x] == 1) {
				answer++;
				dfs(y, x);
			}
		}
	}
	if (table[1000][1000] == 2)
		answer--;
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Logo();
}
