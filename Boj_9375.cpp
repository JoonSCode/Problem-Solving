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
	unordered_map<string, int> map;
	for (int i = 0; i < N; i++) {
		string a, b;
		cin >> a >> b;
		auto it = map.find(b);
		if (it == map.end())
			map.insert({ b,1 });
		else
			it->second++;
	}
	int answer = 1;
	for (pair<string, int> a : map)
		answer *= a.second + 1;
	cout << answer - 1 << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--)
		test();
}
