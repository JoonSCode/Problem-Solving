//Main idea: 1. 한 칸을 반복해서 갈 수 있다. 2.메모이제이션
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
string word;
char table[100][100];
vector<vector<vector<int>>> cache;

void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int a = 0; a < M; a++) {
			char ch;
			cin >> ch;
			table[i][a] = ch;
		}
	}
	cin >> word;
	cache.resize(N, vector < vector<int>>(M, vector<int>(word.size(), -1)));
}


int run(const int& idx, const int& y, const int& x) {//dfs
	char next = word[idx];
	vector<int>& ret = cache[y][x];//메모이제이션
	
	if (ret[idx - 1] != -1) 
		return ret[idx - 1];

	if (idx == word.size())
		return ret[idx - 1] = 1;

	int s = 0;
	for (int i = 1; i <= K; i++) {//상하 좌우로 1부터 K만큼 이동할 수 있는지 확인하고 해당 값이 찾고자 하는 값인 경우 실행
		if (i + y < N && table[i + y][x] == next)
			s +=run(idx + 1, i + y, x);
		if (0 <= y - i && table[y - i][x] == next)
			s += run(idx + 1, y - i, x);
		if (x + i < M && table[y][x + i] == next)
			s += run(idx + 1, y, x + i);
		if (0 <= x - i && table[y][x - i] == next)
			s += run(idx + 1, y, x - i);
	}
	return ret[idx - 1] = s;
}

void wordTable() {
	Input();
	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int a = 0; a < M; a++) {
			if (table[i][a] == word[0]) {
				answer += run(1, i, a);
			}
		}
	}
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	wordTable();
}
