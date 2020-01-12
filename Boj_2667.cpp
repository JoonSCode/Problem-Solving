//Main idea: Bfs 순회 
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int area = 0;
int size_of_area[625] = { 0, };

void Bfs(vector<vector<int>>&map, const int& x, const int& y) {
	map[x][y] = 0;
	size_of_area[area]++;
	if (x + 1 != map.size()) {
		if (map[x + 1][y] == -1) {
			Bfs(map, x + 1, y);
		}
	}
	if (x != 0) {
		if (map[x - 1][y] == -1) {
			Bfs(map, x - 1, y);
		}
	}
	if (y != 0){
		if (map[x][y - 1] == -1) {
			Bfs(map, x, y - 1);
		}
	}
	if (y + 1 != map.size()) {
		if (map[x][y + 1] == -1) {
			Bfs(map, x, y + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<vector<int>> map(N);
	for (int i = 0; i < N; i++) {
		for (int p = 0; p < N; p++) {
			char tmp;
			cin >> tmp;
			if (tmp == '1')
				map[p].push_back(-1);
			else 
				map[p].push_back(0);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int p = 0; p < N; p++) {
			if (map[p][i] != 0) {//Bfs한번 돌 때 마다 출발 지점에서 연결된 곳은 다 순회하므로 수행시마다 집합 라벨링 다르게 한다.
				area++;

				Bfs(map, p, i);
			}
		}
	}
	sort(size_of_area, size_of_area + area + 1);
	cout << area << "\n";
	for (int i = 1; i <= area; i++) {
		cout << size_of_area[i] << "\n";
	}
}
