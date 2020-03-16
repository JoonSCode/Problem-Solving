//Main idea: bottom up방식으로 경우 저장
#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int cache[100001];

void input() {
	cin >> N >> M;
	memset(cache, -1, sizeof(cache));
	cache[N] = 0;
}

int run(int num) {
	for (int i = N; i >= 0; i--) //현재 위치보다 뒤 인곳 이동횟수 입력(뒤로 이동 후 * 2 이동하는 경우 존재 할 수 있으므로)
		cache[i] = N - i;
	for (int i = N / 2; i <= M + 1; i++) {// N/2부터 그 곳에서 이동할 수 있는 경우 갱신
		int a = cache[i];
		if (i *2 <= M+1 &&(cache[i * 2] == -1 || cache[i * 2] > a + 1))
			cache[i * 2] = a + 1;
		if (cache[i + 1] == -1 || cache[i + 1] > a + 1)
			cache[i + 1] = a + 1;
		if (i > 0 &&(cache[i - 1] == -1 || cache[i - 1] > a + 1)) {//현재에서 뒤로 가는 것이 이전에 알던 경로 보다 빠른경우 이때 이전에서 다시 갱신 필요
			cache[i - 1] = a + 1;
			i-=2;
		}
	}
	return cache[num];
}

void HIDENSEEK() {
	input();
	cout<<run(M);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	HIDENSEEK();
}
