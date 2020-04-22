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

void test() {
	int N, M;
	cin >> N >> M;
	vector<int> tmp(N, 1);
	for (int i = 0; i < M; i++)
		tmp[i] = 0;
	do {
		for (int i = 0; i < N; i++) {
			if (tmp[i] == 0)
				cout << i + 1 << " ";
		}
			cout << "\n";
	} while (next_permutation(tmp.begin(), tmp.end()));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
