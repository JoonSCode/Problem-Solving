#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N,K;
int cache[10001];
vector <int> value;

void coin(int num) {//가치가 num인 동전을 가지고 더 만들 수 있는 경우 추가
	for (int i = 0; i <= K - num; i++)
		cache[i + num] += cache[i];
}

void input() {
	memset(cache, 0, sizeof(cache));
	cache[0] = 1;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		value.push_back(tmp);
	}
	sort(value.begin(), value.end());
}

int main() {                                                           
	cin >> N >> K;
	input();
	for(int num: value)
		coin(num);
	cout << cache[K];
}
