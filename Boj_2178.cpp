//Main idea: 도착표시를 depth로 하기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int input(vector<vector<int>>&, const int&, const int&);
void Traversal(vector<vector<int>>&, queue<pair<int, int>>&, const int&, const int&, int);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>> chart;	
	queue<pair<int, int>> que1;
	queue<pair<int, int>> que2;

	int Y,X;
	cin >> Y >> X;
	chart.clear();
	chart.resize(Y, vector<int>(X, 0));
	input(chart, X, Y);
	queue<pair<int, int>> que;
	que.push({ 0, 0 });
	chart[0][0] = 1;
	while(!que.empty())
		Traversal(chart, que, X, Y, 1);
}
int input(vector<vector<int>>& chart, const int& w, const int& h) {
	char a;
	int answer = 0;
	for (int i = 0; i < h; i++) {
		for (int n = 0; n < w; n++) {
			cin >> a;
			if ((int)(a - '0') == 1)
				chart[i][n] = -1;//미탐색 지역을 -1로 지정
			else
				chart[i][n] = (int)(a-'0');//벽은 그대로 0으로 지정
		}
	}
	return answer;
}
void Traversal(vector<vector<int>>& chart, queue<pair<int, int>>& que, const int& w, const int& h, int depth) {
	int y = que.front().first;
	int x = que.front().second;
	que.pop();
	if (y == h - 1 && x == w - 1) {
		cout << chart[y][x];
		return;
	}
	pair<int, int> arr[4] = { {-1,0},{0,1},{1,0},{0,-1} };
	for (int i = 0; i < 4; i++) {
		int newY = y + arr[i].first;
		int newX = x + arr[i].second;
		if ((0 <= y + newY && newY < h) && (0 <= newX && newX < w)) {
			if (chart[newY][newX] == -1) {
				chart[newY][newX] = chart[y][x] + 1;//탐색지역을 몇번째에 탐색 했는지로 라벨링함
				que.push({ newY, newX });
			}
		}
	}
}
