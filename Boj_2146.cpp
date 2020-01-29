#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

void input(vector<vector<int>>& data);
void DFS(vector<vector<int>> & data, set<pair<int,int>>&, int& y, int& x, int group);
bool BFS(vector<vector<int>>&, queue<pair<int,int>>&, const int& y, const int& x, int& answer, int& depth);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> data;

	int N;
	cin >> N;
	data.resize(N, vector<int>(N, 0));
	input(data);
	int group = 1;
	set<pair<int, int>> leaves;
	for (int i = 0; i < data.size(); i++) {
		for (int n = 0; n < data.size(); n++) {
			if (data[i][n] == -1) {
				DFS(data, leaves, i, n, group);
				group++;
			}
		}
	}



	int answer = 100000;
	for (pair<int, int> leaf : leaves) {
		queue<pair<int, int>> que;
		que.push(leaf);

		int depth = 0;
		vector < vector<int>> n_data = data;
		bool find = false;
	//	cout << "-----------------새롭게 시작:  " << "y: " << leaf.first << "\tx: " << leaf.second << "\n";
//		cout << "-----------------------------------------\n";

		while (!find && !que.empty()) {
			queue<pair<int, int>> n_que;
			while (!find && !que.empty()) {
				int y = que.front().first;
				int x = que.front().second;
				que.pop();
				find = BFS(n_data, n_que, y, x, answer, depth);
//				cout << "find: " << find << "\n";
			}
			que = n_que;
			depth++;
		}


	//	cout << "현재 정답: " << answer << "\n";
	}
	cout << answer;
}
void input(vector<vector<int>>& data) {
	for (int i = 0; i < data.size(); i++) {
		for (int n = 0; n < data.size(); n++) {
			int a;
			cin >> a;
			if(a== 1)
				data[i][n] = -1;
		}
	}
}
void DFS(vector<vector<int>>& data, set<pair<int,int>>& leaves, int& y, int& x, int group) {
	data[y][x] = group;
	pair<int, int> arr[4] = { {-1,0},{0,1},{1,0},{0,-1} };
	for (int i = 0; i < 4; i++) {
		int newY = y + arr[i].first;
		int newX = x + arr[i].second;
		if ((0 <= y + newY && newY < data.size()) && (0 <= newX && newX < data.size())) {
			if (data[newY][newX] == -1) {
				DFS(data, leaves, newY, newX, group);
			}
			else if(data[newY][newX] == 0){//한 면이라도 다른 곳과 연결되어 있는 곳
				leaves.insert({ y, x });
			}
		}
	}
}
bool BFS(vector<vector<int>>& data, queue<pair<int,int>>& que, const int& y, const int& x, int& answer, int&depth) {
	int group_no = data[y][x];
	pair<int, int> arr[4] = { {-1,0},{0,1},{1,0},{0,-1} };
//	cout << "---------------" << group_no << "에 대해 검사중\n";
	for (int i = 0; i < 4; i++) {
		int newY = y + arr[i].first;
		int newX = x + arr[i].second;
		if ((0 <= y + newY && newY < data.size()) && (0 <= newX && newX < data.size())) {
			if (data[newY][newX] == 0) {
				data[newY][newX] = group_no;
				que.push({ newY, newX });
		//		cout << "경유중!!  newY: " << newY << "\tnewX: " << newX << "  깊이: " << depth << " 그룹: " << data[newY][newX] << "\n";
			}
			else if (data[newY][newX] != group_no) {//다른 섬에 도착한 경우
		//		cout << "도착!!!  newY: " << newY << "\tnewX: " << newX << "   깊이: " << depth << " 그룹: " << data[newY][newX] << "\n";
				if (depth < answer) 
					answer = depth;	
				return true;//도착했음을 알림
			}
		}
	}
	return false;
}
