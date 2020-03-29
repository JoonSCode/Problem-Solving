#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

void Test() {
	int N, A, B, C;
	long long answer = 0;
	cin >> N;
	vector<int> nop(N);
	for (int i = 0; i < N; i++) {
		cin >> A;
		nop[i] =A;
	}
	cin >> B >> C;

	for (int& a : nop) {
		a -= B;
		answer++;
		if(a>0)
			a% C == 0 ? answer += (long long)a / C : answer += (long long)a / C + 1;
	}
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Test();
}
