//Main idea: heap(priorty_queue) 사용법
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

int N;

void test() {
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (N--) {
		int tmp;
		cin >> tmp;
		if (tmp)
			pq.push(tmp);
		else {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
