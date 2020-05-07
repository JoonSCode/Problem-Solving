//Main idea: input정렬, 
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
vector<int> ans;
vector<int> vec;

void backTracking(int start, int cnt) {
	if (cnt == M) {
		for (const int& a : ans)
			cout << a << " ";
		cout << "\n";
		return;
	}
	for (int i = start; i < N; i++) {
		ans.push_back(vec[i]);
		backTracking(i, cnt + 1);//중복을 허용하기 위해 i+1이 아닌 i로 한다.
		ans.pop_back();
	}
}

void test() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
	backTracking(0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
