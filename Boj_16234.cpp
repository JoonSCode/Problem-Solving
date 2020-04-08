//Main idea: BFS지만 모든 점에 대해 돌릴때 que에 들어갔던 것들을 따로 저장해야한다.
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

int N, L, R;
vector<vector<int>> Country;
vector<vector<int>> isVisited;

vector<pair<int, int>> tmp_vec;


pair<int, int> od[4] = { {1,0},{-1,0},{0,1},{0,-1} };

void move(const vector<pair<int, int>>& a, int& sum) {//연합의 인구를 갱신하는 함수
	sum /= a.size();
	for (const pair<int, int>& b : a) 
		Country[b.first][b.second] = sum;
}

int Dfs(int r, int c) {//연합을 찾는 함수
	int sum = 0;
	tmp_vec.clear();
	tmp_vec.push_back({ r,c });
	isVisited[r][c] = 1;

	for(int i = 0; i < tmp_vec.size(); i++){
		int y = tmp_vec[i].first;
		int x = tmp_vec[i].second;
		int val = Country[y][x];
		sum += val;

		for (const pair<int, int>& a : od) {
			int ny = a.first + y;
			int nx = a.second + x;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N || isVisited[ny][nx] == 1) continue;
			int nval = Country[ny][nx];
			int diff = abs(val - nval);
			if (L <= diff && diff <= R) {
				isVisited[ny][nx] = 1;
				tmp_vec.push_back({ ny,nx });
			}
		}
	}
	return sum;
}

void Test() {
	int answer = 0;
	cin >> N >> L >> R;
	Country.resize(N, vector<int>(N));

	for (int y = 0; y < N; y++) {
		int tmp;
		for (int x = 0; x < N; x++) {
			cin >> tmp;
			Country[y][x] = tmp;
		}
	}

	while (1) {
		isVisited.clear();
		isVisited.resize(N, vector<int>(N, 0));
		vector<vector<pair<int, int>>> vec;
		vector<int> sums;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				int& ret = isVisited[y][x];
				if (ret != 0) continue;
				sums.push_back(Dfs(y, x));//연합의 총 인구 수
				vec.push_back(tmp_vec);//연합들 벡터에 추가
			}
		}
		if (vec.size() == N * N)//1개의 국가로 이루어진 연합만 있는 경우 종료
			break;
		for (int i = 0; i < vec.size(); i++)//인구 갱신
			move(vec[i], sums[i]);
		answer ++;
	}
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    Test();
}
