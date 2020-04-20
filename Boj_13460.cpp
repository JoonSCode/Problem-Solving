//Main idea: 1.상하좌우 이동별로 함수 분류 2.이동 가능한 지 확인, 이동 후 올바른 이동인지 확인에 주의
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

int N, M;
vector<vector<char>> board;
pair<char, char> ansSet[7] = { {'.','.'}, {'R','.'}, {'.','R'}, {'R','B'},{'B','R'},{'B','.'} , {'.','B'} };//이동 후 나올 수 있는 공의 상태
pair<int, int> red, blue;


void input() {
	cin >> N >> M;
	board.resize(N, vector<char>(M));
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			char tmp;
			cin >> tmp;
			board[y][x] = tmp;
			if (tmp == 'B') blue = { y,x };
			if (tmp == 'R') red = { y,x };
		}
	}
}

bool moveLeft(vector<vector<char>>& Map, pair<int, int>& a) {//.이 아닌 것을 발견할 때 까지 쭉 이동
	if (Map[a.first][a.second - 1] != '.' && Map[a.first][a.second - 1] != 'O')
		return true;
	while (Map[a.first][a.second - 1] == '.') {
		char ch = Map[a.first][a.second];
		Map[a.first][a.second - 1] = ch;
		Map[a.first][a.second] = '.';
		a.second--;
	}
	if (Map[a.first][a.second - 1] == 'O')//o를 마주친경우 구멍에 들어가게 함
		Map[a.first][a.second] = '.';
	return false;
}
bool moveRight(vector<vector<char>>& Map, pair<int, int>& a) {
	if (Map[a.first][a.second + 1] != '.' && Map[a.first][a.second + 1] != 'O')
		return true;
	while (Map[a.first][a.second + 1] == '.') {
		char ch = Map[a.first][a.second];
		Map[a.first][a.second + 1] = ch;
		Map[a.first][a.second] = '.';
		a.second++;
	}
	if (Map[a.first][a.second + 1] == 'O')
		Map[a.first][a.second] = '.';
	return false;
}
bool moveUp(vector<vector<char>>& Map, pair<int, int>& a) {
	if (Map[a.first - 1][a.second] != '.' && Map[a.first - 1][a.second] != 'O')
		return true;
	while (Map[a.first - 1][a.second] == '.') {
		char ch = Map[a.first][a.second];
		Map[a.first - 1][a.second] = ch;
		Map[a.first][a.second] = '.';
		a.first--;
	}
	if (Map[a.first - 1][a.second] == 'O')
		Map[a.first][a.second] = '.';
	return false;
}
bool moveDown(vector<vector<char>>& Map, pair<int, int>& a) {
	if (Map[a.first + 1][a.second] != '.' && Map[a.first + 1][a.second] != 'O')
		return true;
	while (Map[a.first + 1][a.second] == '.') {
		char ch = Map[a.first][a.second];
		Map[a.first + 1][a.second] = ch;
		Map[a.first][a.second] = '.';
		a.first++;
	}
	if (Map[a.first + 1][a.second] == 'O')
		Map[a.first][a.second] = '.';
	return false;
}

int check(vector<vector<char>>& Map, pair<int, int>a, pair<int, int>b) {
	char chA = Map[a.first][a.second];
	char chB = Map[b.first][b.second];
	for (int i = 0; i < 7; i++) {
		if (make_pair(chA, chB) != ansSet[i]) continue;
		return i;
	}
}
//지도를 원위치하고 공의 위치도 원래대로 옮긴다.
void init(vector<vector<char>>& Map, pair<int, int>& r, pair<int, int>& b, pair<int, int>& left, pair<int, int>& right, pair<int, int>& above, pair<int, int>& below) {
	Map[below.first][below.second] = '.';
	Map[above.first][above.second] = '.';
	Map[r.first][r.second] = 'R';
	Map[b.first][b.second] = 'B';

	Map[left.first][left.second] = '.';
	Map[right.first][right.second] = '.';
	Map[r.first][r.second] = 'R';
	Map[b.first][b.second] = 'B';

	left = r;
	right = b;
	above = r;
	below = b;

	if (r.second > b.second) {//좌 우 이동시에 먼저 이동할 것 찾기 위해
		left = b;
		right = r;
	}
	if (r.first > b.first) {//상 하 이동시에 먼저 이동할 것 찾기 위해
		above = b;
		below = r;
	}
}



int dfs(vector<vector<char>> Map, pair<int, int>r, pair<int, int>b, int cnt, int move) {
	if (cnt > 10)//10회 이상의 움직임은 막는다.(기저사례)
		return 11;
	pair<int, int>left = r;
	pair<int, int>right = b;
	pair<int, int>above = r;
	pair<int, int>below = b;
	int ans = 11;

	if (r.second > b.second) {
		left = b;
		right = r;
	}
	if (r.first > b.first) {
		above = b;
		below = r;
	}
//초기 init
	if (move != 2) {//이전의 움직임과 반대되는 움직임을 취하지 않도록 한다.(ex 위아래 계속 반복하는 경우 제거)
		bool b1 = moveDown(Map, below);
		bool b2 = moveDown(Map, above);
		if (b1 && b2) {}//둘다 이동 못한 경우
		else {
			int idx = check(Map, below, above);
			if (idx == 5 || idx == 6)//성공한 경우
				ans = min(ans, cnt);
			else if (idx == 3 || idx == 4) {//올바른 이동의 경우
				char chA = Map[below.first][below.second];
				char chB = Map[above.first][above.second];
				int tmp = 0;
				if (chA == 'R')
					tmp = dfs(Map, below, above, cnt + 1, 1);
				else
					tmp = dfs(Map, above, below, cnt + 1, 1);
				ans = min(ans, tmp);
			}
		}
		init(Map, r, b, left, right, above, below);//다시 재정렬
	}

	if (move != 1) {
		bool b1 = moveUp(Map, above);
		bool b2 = moveUp(Map, below);
		if (b1 && b2) {}
		else {
			int idx = check(Map, above, below);
			if (idx == 5 || idx == 6)
				ans = min(ans, cnt);
			else if (idx == 3 || idx == 4) {
				char chA = Map[below.first][below.second];
				char chB = Map[above.first][above.second];

				int tmp = 0;
				if (chA == 'R')
					tmp = dfs(Map, below, above, cnt + 1, 2);
				else
					tmp = dfs(Map, above, below, cnt + 1, 2);
				ans = min(ans, tmp);
			}
		}
		init(Map, r, b, left, right, above, below);

	}

	if (move != 4) {
		bool b1 = moveLeft(Map, left);
		bool b2 = moveLeft(Map, right);
		if (b1 && b2) {}
		else {
			int idx = check(Map, left, right);
			if (idx == 5 || idx == 6)
				ans = min(ans, cnt);
			else if (idx == 3 || idx == 4) {
				char chA = Map[left.first][left.second];
				char chB = Map[right.first][right.second];

				int tmp = 0;
				if (chA == 'R')
					tmp = dfs(Map, left, right, cnt + 1, 3);
				else
					tmp = dfs(Map, right, left, cnt + 1, 3);
				ans = min(ans, tmp);
			}
		}
		init(Map, r, b, left, right, above, below);

	}

	if (move != 3) {
		bool b1 = moveRight(Map, right);
		bool b2 = moveRight(Map, left);
		if (b1 && b2) {}
		else {
			int idx = check(Map, right, left);
			if (idx == 5 || idx == 6)
				ans = min(ans, cnt);
			else if (idx == 3 || idx == 4) {
				char chA = Map[right.first][right.second];
				char chB = Map[left.first][left.second];

				int tmp = 0;
				if (chA == 'R')
					tmp = dfs(Map, right, left, cnt + 1, 4);
				else
					tmp = dfs(Map, left, right, cnt + 1, 4);
				ans = min(ans, tmp);
			}
		}
		init(Map, r, b, left, right, above, below);

	}
	return ans;
}

void solution() {
	input();
	int ans = dfs(board, red, blue, 1, 0);
	if (ans == 11)//10번 안에 해결 불가능한 경우
		cout << "-1";
	else
		cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	solution();
}
