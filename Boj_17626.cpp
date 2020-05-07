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
vector<int> nums(223,987654321);
int answer = 5;

void run(int cnt, int val, int idx) {//현재까지 사용한 제곱수 갯수, 남은 값, 이전에 사용한 값의idx (N에서 빼가며 계산)
	if (cnt == 4 && val != 0)
		return;
	if (val == 0) {
		answer = min(cnt, answer);
    return;
	}
	for (int i = idx; i >= 0; i--) {
		if (nums[i] > val) continue;
		run(cnt + 1, val - nums[i], i);
	}
}

void test() {
	cin >> N;
	for (int i = 1; i <= sqrt(N); i++) 
		nums[i - 1] = i * i;
	run(0, N, nums.size() - 1);
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
