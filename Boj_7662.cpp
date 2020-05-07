//Main idea: multiset
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
	int N;
	multiset<int> ms;
	cin >> N;

	while (N--) {
		char a;
		int num;
		cin >> a >> num;
		if (a == 'D') {
			if (ms.empty()) continue;
			if (num == 1)
				ms.erase(--ms.end());
			else
				ms.erase(ms.begin());
		}
		else 
			ms.insert(num);		
	}

	if (ms.empty())
		cout << "EMPTY\n";
	else
		cout << *--ms.end()  << " " << *ms.begin() << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
		test();
}
