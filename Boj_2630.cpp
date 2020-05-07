//Main idea: 완탐, 구현에 초점
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
#include <utility>

using namespace std;

int N;
vector<vector<int>> paper;
int answer[2] = { 0, };

bool check(const int& sy, const int& sx, const int& ey, const int& ex) {
	int color = paper[sy][sx];//맨 왼쪽 위 색을 기준으로 색 체크
	for (int y = sy; y <= ey; y++) {
		for (int x = sx; x <= ex; x++) 
			if (paper[y][x] != color) return false;
	}
	answer[color]++;//모두 같은 경우 갯수 추가
	return true;
}

void run(int sy, int sx, int ey, int ex) {
	if (check(sy, sx, ey, ex)) return;//하나의 색인 경우
	run(sy, sx, (sy + ey) / 2, (sx + ex) / 2);
	run(sy, (sx + ex) / 2 + 1, (sy + ey) / 2, ex);
	run((sy + ey) / 2 + 1, sx, ey, (sx + ex) / 2);
	run((sy + ey) / 2 + 1, (sx + ex) / 2 + 1, ey, ex);
}

void test() {
	cin >> N;
	paper.resize(N, vector<int>(N));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int tmp;
			cin >> tmp;
			paper[y][x] = tmp;
		}
	}
	run(0, 0, N - 1, N - 1);
	cout << answer[0] << "\n" << answer[1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
