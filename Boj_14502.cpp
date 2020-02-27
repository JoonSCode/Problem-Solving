//Main idea: 완전탐색으로 시간 만족하는지 확인, 효율적 
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int bf(queue<pair<int, int>> virus_arr, vector<vector<int>>& map_arr, int size) {
	pair<int, int> arr[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
	
	while (!virus_arr.empty()) {//bfs
		int x = virus_arr.front().first;
		int y = virus_arr.front().second;
		virus_arr.pop();
		for (int i = 0; i < 4; i++) {
			int new_x = x + arr[i].first;
			int new_y = y + arr[i].second;
			if (0 <= new_x && new_x < map_arr[0].size() && 0 <= new_y && new_y < map_arr.size()) {
				if (map_arr[new_y][new_x] == 0) {
					map_arr[new_y][new_x] = 2;
					virus_arr.push({ new_x, new_y });
					size--;
				}
			}
		}
	}
	return size;
}


void lab() {
	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> empty_arr;
	queue<pair<int, int>> virus_arr;
	vector<vector<int>> map_arr(N, vector<int>(M, 0));

	int answer = 0;

	for (int i = 0; i < N; i++) {
		for (int a = 0; a < M; a++) {
			int tmp;
			cin >> tmp;
			if (tmp == 0)
				empty_arr.push_back({ a,i });//x,y
			else if (tmp == 2)
				virus_arr.push({ a,i });//x,y
			map_arr[i][a] = tmp;
		}
	}

	for (int i = 0; i < empty_arr.size()-2; i++) {//벽을 세우는 것을 완전 탐색으로
		for (int a = i + 1; a < empty_arr.size()-1; a++) {
			for (int n = a + 1; n < empty_arr.size(); n++) {
				vector < vector<int>> new_map = map_arr;
				new_map[empty_arr[i].second][empty_arr[i].first] = 1;
				new_map[empty_arr[a].second][empty_arr[a].first] = 1;
				new_map[empty_arr[n].second][empty_arr[n].first] = 1;
				answer = max(answer, bf(virus_arr, new_map, empty_arr.size()-3));
			}
		}
	}
	cout << answer;
}

int main() {
	lab();
}
