//Main idea: dfs 후에 코드 다시 축약할 
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
int answer = 987654321;
vector<vector<int>> room;
vector<pair<int, int>> nums;

void checkDown(int& y, int& x, int idx) {
	for (int i = y + 1; i < N; i++) {
		if (room[i][x] == 6)
			break;
		if (room[i][x] == 0)
			room[i][x] = -idx;
	}
}
void unCheckDown(int& y, int& x, int idx) {
	for (int i = y + 1; i < N; i++) {
		if (room[i][x] == 6)
			break;
		if (room[i][x] == -idx)
			room[i][x] = 0;
	}
}

void checkUp(int& y, int& x, int idx) {
	for (int i = y - 1; i >= 0; i--) {
		if (room[i][x] == 6)
			break;
		if (room[i][x] == 0)
			room[i][x] = -idx;
	}
}
void unCheckUp(int& y, int& x, int idx) {
	for (int i = y - 1; i >= 0; i--) {
		if (room[i][x] == 6)
			break;
		if (room[i][x] == -idx)
			room[i][x] = 0;
	}
}
void checkRight(int& y, int& x, int idx) {
	for (int i = x + 1; i < M; i++) {
		if (room[y][i] == 6)
			break;
		if (room[y][i] == 0)
			room[y][i] = -idx;
	}
}
void unCheckRight(int& y, int& x, int idx) {
	for (int i = x + 1; i < M; i++) {
		if (room[y][i] == 6)
			break;
		if (room[y][i] == -idx)
			room[y][i] = 0;
	}
}
void checkLeft(int& y, int& x, int idx) {
	for (int i = x - 1; i >= 0; i--) {
		if (room[y][i] == 6)
			break;
		if (room[y][i] == 0)
			room[y][i] = -idx;
	}
}
void unCheckLeft(int& y, int& x, int idx) {
	for (int i = x - 1; i >= 0; i--) {
		if (room[y][i] == 6)
			break;
		if (room[y][i] == -idx)
			room[y][i] = 0;
	}
}

void Dfs(int idx) {
	if (idx == nums.size()) {
		int val = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (room[y][x] == 0)
					val++;
			}
		}
		answer = min(answer, val);
		return;
	}
	int y = nums[idx].first;
	int x = nums[idx].second;
	int type = room[y][x];
	switch (type) {
	case 1:
		checkUp(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckUp(y, x, idx + 1);

		checkDown(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckDown(y, x, idx + 1);

		checkLeft(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckLeft(y, x, idx + 1);

		checkRight(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckRight(y, x, idx + 1);
		break;
	case 2:
		checkUp(y, x, idx + 1);
		checkDown(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckUp(y, x, idx + 1);
		unCheckDown(y, x, idx + 1);

		checkLeft(y, x, idx + 1);
		checkRight(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckLeft(y, x, idx + 1);
		unCheckRight(y, x, idx + 1);

		break;
	case 3:
		checkUp(y, x, idx + 1);
		checkLeft(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckUp(y, x, idx + 1);
		unCheckLeft(y, x, idx + 1);

		checkUp(y, x, idx + 1);
		checkRight(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckUp(y, x, idx + 1);
		unCheckRight(y, x, idx + 1);

		checkDown(y, x, idx + 1);
		checkLeft(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckDown(y, x, idx + 1);
		unCheckLeft(y, x, idx + 1);

		checkDown(y, x, idx + 1);
		checkRight(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckDown(y, x, idx + 1);
		unCheckRight(y, x, idx + 1);

		break;
	case 4:
		checkUp(y, x, idx + 1);
		checkDown(y, x, idx + 1);
		checkLeft(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckUp(y, x, idx + 1);
		unCheckDown(y, x, idx + 1);
		unCheckLeft(y, x, idx + 1);

		checkUp(y, x, idx + 1);
		checkDown(y, x, idx + 1);
		checkRight(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckUp(y, x, idx + 1);
		unCheckDown(y, x, idx + 1);
		unCheckRight(y, x, idx + 1);

		checkDown(y, x, idx + 1);
		checkLeft(y, x, idx + 1);
		checkRight(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckDown(y, x, idx + 1);
		unCheckLeft(y, x, idx + 1);
		unCheckRight(y, x, idx + 1);

		checkUp(y, x, idx + 1);
		checkLeft(y, x, idx + 1);
		checkRight(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckUp(y, x, idx + 1);
		unCheckLeft(y, x, idx + 1);
		unCheckRight(y, x, idx + 1);
		break;
	case 5:
		checkUp(y, x, idx + 1);
		checkDown(y, x, idx + 1);
		checkLeft(y, x, idx + 1);
		checkRight(y, x, idx + 1);
		Dfs(idx + 1);
		unCheckUp(y, x, idx + 1);
		unCheckDown(y, x, idx + 1);
		unCheckLeft(y, x, idx + 1);
		unCheckRight(y, x, idx + 1);
		break;
	}
}

void Test() {
	cin >> N >> M;
	room.resize(N, vector<int>(M));
	int tmp;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> tmp;
			room[y][x] = tmp;
			if (tmp == 0 || tmp == 6)
				continue;
			nums.push_back({ y,x });
		}
	}
	Dfs(0);
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Test();
}
