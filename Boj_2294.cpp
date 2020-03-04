//Main idea: 중복 제거 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector <int> cache(10001,10001);

void run(int num) {
	for (int i = 0; i <= K - num; i++)
		cache[i + num] = min(cache[i + num], cache[i] + 1);
}

void output() {
	int ans = cache[K];
	if (ans == 10001)
		cout << "-1";
	else
		cout << ans;
}

void coin() {
	cin >> N >> K;
	int tmp;
	cache[0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp <= K)
			run(tmp);
	}
	output();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	coin();
}
