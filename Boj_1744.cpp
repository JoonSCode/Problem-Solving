//Main idea: dp로 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;
vector<long long> cache;
#define LLONG_MAX 9223372036854775807

void input() {
	cin >> N;
	arr.resize(N, 0);
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		cache.push_back(LLONG_MAX);
	}
	sort(arr.begin(), arr.end());
}

long long run(const int& a) {
	long long& ret = cache[a];
	if (ret != LLONG_MAX)
		return ret;
	if (a == N - 1)
		return arr[a];
	else if (a == N - 2) {
		return max(arr[a] + arr[a + 1], arr[a] * arr[a + 1]);
	return ret = max(arr[a] + run(a + 1), arr[a] * arr[a + 1] + run(a + 2));
}

void Binding() {
	input();
	cout << run(0);
}	

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Binding();
}
