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
	int x, n, m;
	cin >> x >> n >> m;
	for (int i = 0; i < n; i++) {
		if (x <= 10 * m) {
			cout << "YES\n";
			return;
		}
		x = x / 2 + 10;
	}
	if (x > 10 * m)
		cout << "NO\n";
	else
		cout << "YES\n";
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while(T--)
		test();
}
