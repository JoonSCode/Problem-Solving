//Main idea: dp의 
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <utility>

using namespace std;

int N;
vector<int> vec(1000001, 987654321);
vector<int> ans;

void dp(int num) {//결정된 dp값을 토대로 내려가면서 ans에 값을 추가한다.
	int tmp = 987654321;
	int min_num = 0;
	ans.push_back(num);
	if (num == 1)
		return;
	if (num % 3 == 0) {
		if (tmp > vec[num/3]) {
			tmp = vec[num / 3];
			min_num = num / 3;
		}
	}
	if (num % 2 == 0) {
		if (tmp > vec[num / 2]) {
			tmp = vec[num / 2];
			min_num = num / 2;
		}
	}
	if (tmp > vec[num - 1]) 
		min_num = num - 1;

	dp(min_num);
}

void init() {//bottom up으로 dp를 채운다.
	for (int i = 1; i < 1e6; i++) {
		int& ret = vec[i];
		vec[i + 1] = min(vec[i + 1], ret + 1);
		if (i * 2 > 1e6) continue;
		vec[i * 2] = min(vec[i * 2], ret + 1);
		if (i * 3 > 1e6) continue;
		vec[i * 3] = min(vec[i * 3], ret + 1);
	}
}

void test() {
	cin >> N;
	vec[1] = 0;
	vec[2] = 1;
	vec[3] = 1;
	init();
	dp(N);
	cout << vec[N]<<"\n";
	for(int a :ans)
		cout << a << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
