//Main idea: 1. A가 꼭 0인 상태를 유지하려 할 필요는 없다. 2. 6개의 부을 수 있는 경우가 존재한다. 3. C 는 A와 B에 종속된다.
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct state {
	int a, b;
	state(int q, int w) {
		a = q;
		b = w;
	}
};

int A, B, C;
bool check[201][201];
vector<int>answer;
queue<state>que;

void Input() {
	cin >> A >> B >> C;
}

void pour(int x, int y) {
	if (!check[x][y]) {
		check[x][y] = true;
		que.push(state(x, y));
	}
}

void run() {
	pour(0, 0);
	while (!que.empty()) {
		state st = que.front();
		int X = st.a;
		int Y = st.b;
		int Z = C - st.a - st.b;
		que.pop();
		if (!X)
			answer.push_back(Z);

		//X->Y
		int water = min(X, B - Y);
		pour(X - water, Y + water);
		//X->Z
		water = min(X, C - Z);
		pour(X - water, Y);
		//Y->X
		water = min(Y, A - X);
		pour(X + water, Y - water);
		//Y->Z
		water = min(Y, C - Z);
		pour(X, Y - water);
		//Z->X
		water = min(A - X, Z);
		pour(X + water, Y);
		//Z->Y
		water = min(B - Y, Z);
		pour(X , Y + water);
	}
}

void Bottle() {
	Input();
	run();
	sort(answer.begin(), answer.end());
	for (int a : answer)
		cout << a << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Bottle();
}
