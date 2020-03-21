#include <iostream>
//Main idea: 알바벳을 숫자로 바꿔서 배열로 중복 처리 + dfs
#include <vector>
#include <algorithm>

using namespace std;

int R, C;
char Map[20][20];
pair<int, int> arr[4] = { {1,0},{-1,0},{0,1},{0,-1} };

void Input() {
	cin >> R >> C;
	char tmp;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> tmp;
			Map[y][x] = tmp;
		}
	}
}

int Run(vector<int>& alp, const int y, const int x) {//dfs 이번 위치에 해당하는 알파벳 체크
	int num = Map[y][x] - 'A';
	if (alp[num] == 1)
		return 0;
	alp[num] = 1;
	int answer = 0;
	for (pair<int, int>& a : arr) {
		int nx = a.second + x;
		int ny = a.first + y;

		if (ny < 0 || nx < 0 || ny >= R || nx >= C)
			continue;
		answer = max(answer, Run(alp, ny, nx) + 1);
	}
	alp[num] = 0;
	return answer;
}


void Alphabet() {
	Input();
	vector<int> arr(26,0);
	cout << Run(arr, 0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Alphabet();
}
