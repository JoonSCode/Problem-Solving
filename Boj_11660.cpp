//Main idea: 행 - 위에서 몇번째인지, 열 - 왼쪽에서 몇번째인지
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

vector<vector<int>> table;
int N, M;

void input() {//input 받으며 summed-area table 만든다.
	cin >> N >> M;
	table.resize(N, vector<int>(N, 0));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int tmp;
			cin >> tmp;
			table[y][x] = tmp;
			if(x != 0)
				table[y][x] += table[y][x - 1];
		}
	}
	for (int y = 1; y < N; y++) {
		for (int x = 0; x < N; x++)
			table[y][x] += table[y - 1][x];
	}
}

void sum() {//행, 열 순으로 input들어오므로 y,x 변경함.
	int x1, y1, x2, y2;
	cin >> y1 >> x1 >> y2 >> x2;
	x1--;	y1--;	x2--;	y2--;
	int val = table[y2][x2];
	if(x1 != 0) 
		val -= table[y2][x1 - 1];
	if (y1 != 0)
		val -= table[y1 - 1][x2];
	if (x1 != 0 && y1 != 0)
		val += table[y1 - 1][x1 - 1];
	cout << val << "\n";
}

void test() {
	input();
	while(M--)
		sum();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
