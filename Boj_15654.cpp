//Main idea: next_permutation으로는 해결 
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
vector<int> vec;
vector<int> ans(10);
vector<int> check(10,0);

void run(int cnt) {
	if (cnt >= M) {
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (check[i] == 1) continue;
		check[i] = 1;
		ans[cnt] = vec[i];
		run(cnt + 1);
		check[i] = 0;
	}
}

void test() {
	cin >> N >> M;
	vec.resize(N);
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		vec[i] = tmp;
	}
	sort(vec.begin(), vec.end());
	run(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

		test();
}
