//Main idea: 1. 누적합 2.이분탐색(변형)
#include <iostream>
#include <algorithm>

using namespace std;

int N;
bool arr[4000001];
long long prime_sum[4000001];
int prime_sz;

int MakePrime() {//소수를 찾고 소수 누적합 배열을 만든다.
	int val = 0;
	int idx = 1;
	for (int i = 2; i <= N; i++) {
		if (arr[i])
			continue;

		prime_sum[idx] = prime_sum[idx - 1] + i;
		if (val == 0 && prime_sum[idx] >= N)
			val = idx;
		for (int n = i + i; n <= N; n += i)
			arr[n] = true;
		idx++;

	}
	prime_sz = idx;
	return val;
}

void Input() {
	cin >> N;
}

bool Bs(const int& val, const int start, const int end) {//val 부터 mid까지의 부분합을 이분 탐색을 이용하여 구한다.
	if (start == end && prime_sum[start] - prime_sum[val] != N)//기저사례
		return false;

	bool ans = false;
	int mid = (start + end) / 2;
	
	if (prime_sum[mid] - prime_sum[val] < N)
		ans = Bs(val, mid + 1, end);
	else if (prime_sum[mid] - prime_sum[val] == N)
		ans = true;
	else
		ans = Bs(val, start, mid);
	return ans;
}

void SumOfNum() {
	Input();
	int end = MakePrime();
	int answer = 0;
	for (int i = 1; i < prime_sz; i++) {
		if (prime_sum[prime_sz - 1] - prime_sum[i - 1] < N)
			break;
		if (Bs(i - 1, i, prime_sz - 1))
			answer++;
	}
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	SumOfNum();
}
