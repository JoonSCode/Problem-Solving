//Main idea: 날마다 순회를 시작해야 하는 지점이 정해져 있다.   전역변수 안쓰기에 초점
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int input(vector<vector<int>>&, queue<pair<int, int>>&, const int&, const int&);
void Traversal(vector<vector<int>>&, const int&, const int&, queue<pair<int, int>>&, queue<pair<int, int>>&, int ,int);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> chart;	
	queue<pair<int, int>> que1;
	queue<pair<int, int>> que2;

	int w,h;
	cin >> w >> h;
	chart.clear();
	chart.resize(h, vector<int>(w, 0));
	int answer = input(chart, que1, w, h);
	int after = 0;
	int day = 0;
	while (1) {
		if (!que1.empty()) {
			while (!que1.empty()) {
				int y = que1.front().first;
				int x = que1.front().second;
				que1.pop();

				Traversal(chart, w, h, que1, que2, y, x);
			}
			after += que1.size() + que2.size();
			day++;
			continue;
		}
		else if(!que2.empty()){
			while (!que2.empty()) {
				int y = que2.front().first;
				int x = que2.front().second;
				que2.pop();

				Traversal(chart, w, h, que2, que1, y, x);
			}
			after += que1.size() + que2.size();
			day++;
			continue;
		}
		else {
			if (answer != after)
				cout << "-1";
			else
				cout << day-1;
			break;
		}
	}
}
int input(vector<vector<int>>& chart, queue<pair<int, int>>& tomato,const int& w, const int& h) {
	int a;
	int answer = 0;
	for (int i = 0; i < h; i++) {
		for (int n = 0; n < w; n++) {
			cin >> a;
			if (a == 0) 
				answer++;
			else if(a == 1)
				tomato.push({ i,n });
			chart[i][n] = a;
		}
	}
	return answer;
}
void Traversal(vector<vector<int>>& chart, const int& w, const int& h, queue<pair<int, int>>& tomato, queue<pair<int, int>>& n_tomato, int y, int x) {
	pair<int, int> arr[4] = { {-1,0},{0,1},{1,0},{0,-1} };
	for (int i = 0; i < 4; i++) {
		int newY = y + arr[i].first;
		int newX = x + arr[i].second;
		if ((0 <= y + newY && newY < h) && (0 <= newX && newX < w)) {
			if (chart[newY][newX] == 0) {
				chart[newY][newX] = 1;
				n_tomato.push({ newY,newX });
			}
		}
	}
}
