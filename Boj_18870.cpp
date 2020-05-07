//Main idea: 정렬 후 중복처리
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
	long long tmp;
	vector<pair<long long, int>> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		vec[i] = { tmp,i };
	}
	sort(vec.begin(), vec.end());
	vector<int> ans(N);
	int idx = -1;
	for (int i = 0; i < N; i++) {
		if (i == 0 || vec[i - 1].first != vec[i].first)	idx++;//같은 값을 가지고 있지 않을 때 idx++
		ans[vec[i].second] = idx;		
	}
	for (int a : ans)
		cout << a << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
