//Main idea: 숫자의 범위 
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

unsigned long long recursive(unsigned long long a, unsigned long long b, unsigned long long c) {//tmp의 범위가 int32 범위라서 최대값에서 제곱시 long long범위를 벗어남
	if (b == 0)
		return 1;
	if (b == 1)
		return a % c;
	unsigned long long tmp = recursive(a, b / 2, c);
	if (b % 2 == 0)
		return tmp * tmp % c;
	else
		return ((tmp * tmp) % c * a) % c;
}

void test() {
	int a, b, c;
	cin >> a >> b >> c;
	cout << recursive(a, b, c);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
