//Main idea: 스티커들과 모눈종이가 주어진다. 모눈 종이에 몇개의 스티커들을 붙일 수 있는지 알아보는 문제. 0 90 180 270으로 돌려서 테스트 하고 못 붙이는 경우 포기
#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> Map;

bool IsPossible(vector<vector<int>> tmp_map, vector<vector<int>>& st, const int& a, const int& b) {//빈곳과 스티커의 모양을 매칭하여서 가능여부 파악
	int height = st.size();
	int width = st[0].size();
	if (a + height > N || b + width > M || b < 0)//모눈종이의 범위를 벗어나는 경우
		return false;
	for (int y = 0; y < st.size(); y++) {
		for (int x = 0; x < st[0].size(); x++) {
			if (st[y][x] == 1) {
				if (tmp_map[y + a][x + b] == 1)
					return false;
				tmp_map[y + a][x + b] = 1;
			}
		}
	}
	Map = tmp_map;
	return true;
}

bool test(vector<vector<int>>& st) {//빈 곳을 찾아 ispossible돌린다.
	int fx = 0;
	for (fx; fx < st[0].size(); fx++) {
		if (st[0][fx] == 1)
			break;
	}
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < M; b++) {
			if (Map[a][b] == 0 && IsPossible(Map, st, a, b - fx))
				return true;
		}
	}
	return false;
}

void rotate(vector<vector<int>>& st) {//스티커를 90도씩 회전 시킨다.
	int height = st.size();
	int width = st[0].size();
	vector<vector<int>> tmp(width, vector<int>(height));

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++)
			tmp[x][height - 1 - y] = st[y][x];
	}
	st = tmp;
}

void Sticker() {
	cin >> N >> M >> K;
	Map.resize(N, vector<int>(M));
	int answer = 0;
	for (int n = 0; n < K; n++) {
		int R, C;
		cin >> R >> C;
		vector<vector<int>> st(R, vector<int>(C));
		int tmp;
		int cnt = 0;
		for (int i = 0; i < R; i++) {//스티커 입력
			for (int n = 0; n < C; n++) {
				cin >> tmp;
				st[i][n] = tmp;
				if (tmp == 1)
					cnt++;
			}
		}
		for (int i = 0; i < 4; i++) {//스티커 테스트 못붙이면 90도 
			if (test(st)) {
				answer += cnt;
				break;
			}
			rotate(st);
		}
	}
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Sticker();
}
