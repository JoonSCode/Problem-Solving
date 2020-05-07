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

void test() {
  int N;
	cin >> N;
	priority_queue<int, vector<int>, less<int>> que;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (tmp)
			que.push(tmp);
		else {
			if (que.empty())
				cout << "0\n";
			else {
				cout << que.top() << "\n";
				que.pop();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
