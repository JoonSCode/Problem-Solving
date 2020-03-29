//Main idea: 1.돌아가야 하는지 여부, 돌아가야하는 함수 등 기능별로 분리하여 구현
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> st(4, vector<int>(8));
int K;
vector<pair<int, int>> order;

void Input() {
	char c;
	for (int i = 0; i < 4; i++) {
		for (int a = 0; a < 8; a++) {
			cin >> c;
			st[i][a] = c - '0';
		}
	}
	cin >> K;
	order.resize(K);
	int a, b;
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		order[i] = { a - 1,b };
	}
}

void MoveR(const int& idx) {
	int l = st[idx][7];
	for (int i = 6; i >= 0; i--)
		st[idx][i + 1] = st[idx][i];
	st[idx][0] = l;
}
void MoveL(const int& idx) {
	int s = st[idx][0];
	for (int i = 1; i < 8; i++)
		st[idx][i - 1] = st[idx][i];
	st[idx][7] = s;
}

void Move(const int& idx, const int& dir) {
	int isMove[4];
	memset(isMove, 0, sizeof(isMove));
	int tidx = idx;
	int tdir = dir;
	while (1) {
		isMove[tidx] = tdir;
		if (tidx == 0)
			break;
		if (st[tidx][6] != st[tidx - 1][2]) {
			tidx--;
			tdir = -tdir;
		}
		else
			break;
	}
	while (1) {
		isMove[tidx] = tdir;
		if (tidx == 3)
			break;
		if (st[tidx][2] != st[tidx + 1][6]) {
			tidx++;
			tdir = -tdir;
		}
		else
			break;
	}
	for (int i = 0; i < 4; i++) {
		if (isMove[i] == 0)
			continue;
		if (isMove[i] == 1)
			MoveR(i);
		else
			MoveL(i);
	}
}

void Test() {
	Input();
	int answer = 0;
	for (pair<int, int>& a : order)
		Move(a.first, a.second);
	for (int i = 0; i < 4; i++) 
		answer += pow(2, i) * st[i][0];
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Test();
}
