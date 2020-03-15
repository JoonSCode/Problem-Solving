//Main idea: 1.중간 부터 넣기 (가장 작은 것 큰것) 2.맨 마지막에 넣는 것이 가장 앞에 갈지 뒤에 
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> arr;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	sort(arr.begin(), arr.end());
}

void SubMax() {
	input();
	vector<int> vec(N, 0);
	int left = (N-1) / 2;
	int right = (N-1) / 2 + 1;
	int idx = 0;

	while (left >= 0 && right < N) {
		if (idx % 2 == 0) {
			vec[left] = arr[idx];
			vec[right] = arr[N - 1 - idx];
		}
		else {
			vec[right] = arr[idx];
			vec[left] = arr[N - 1 - idx];
		}
		idx++;
		left--;
		right++;
	}
	if (N%2 !=0) 
		vec[0] = arr[idx];

	int ans = 0;
	for (int i = 1; i < N - 1; i++) 
		ans += abs(vec[i] - vec[i + 1]);
	ans += max(abs(vec[0] - vec[1]), abs(vec[N - 1] - vec[0]));
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	SubMax();
}
