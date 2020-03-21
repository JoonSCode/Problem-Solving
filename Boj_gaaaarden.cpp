//Main idea: bfs를 두 점에서 해서 같은 뎁스에서 만나는 경우를 체크하는 문제 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, G, R;


void Gaaaaaaaaaarden() {
	cin >> N >> M >> G >> R;
	vector<vector<int>> garden;
	garden.resize(N, vector<int>(M));


	vector<pair<int, int>> possible_place;
	int tmp;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> tmp;
			garden[y][x] = tmp;
			if (tmp == 2)
				possible_place.push_back({ y,x });
		}
	}

	vector<int> vec(possible_place.size());
	int s = possible_place.size() - R - G;
	for (int i = 0; i < s; i++)
		vec[i] = 0;
	for (int i = s; i < s + R; i++)
		vec[i] = 1;
	for (int i = s + R; i < s + R + G; i++)
		vec[i] = 2;

	int answer = 0;

	pair<int, int> arr[4] = { {1,0},{-1,0},{0,1},{0,-1} };

	do {
		vector<vector<int>> tmp_garden = garden;
		queue<pair<int, int>> que;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == 1) {
				que.push(possible_place[i]);
				tmp_garden[possible_place[i].first][possible_place[i].second] = 4;
			}
			else if (vec[i] == 2) {
				que.push(possible_place[i]);
				tmp_garden[possible_place[i].first][possible_place[i].second] = -1;
			}
		}

		int tmp_answer = 0;
		while (!que.empty()) {
			int x = que.front().second;
			int y = que.front().first;
			int val = tmp_garden[y][x];
			que.pop();
			if (val == 3)
				continue;

			if (val < 0)
				val--;
			else
				val++;

			for (pair<int, int>& tmp : arr) {
				int nx = x + tmp.second;
				int ny = y + tmp.first;

				if (0 > nx || nx >= M || 0 > ny || ny >= N)
					continue;
				int& ret = tmp_garden[ny][nx];
				if (ret == 0)
					continue;
				if (ret == 1 || ret == 2) {
					ret = val;
					que.push({ ny,nx });
				}
				else if (val + ret == 3) {
					tmp_answer++;
					ret = 3;
				}
			}
		}
		answer = max(answer, tmp_answer);
	} while (next_permutation(vec.begin(), vec.end()));

	cout << answer;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Gaaaaaaaaaarden();
}
