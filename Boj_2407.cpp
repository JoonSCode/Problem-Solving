//Main idea: long long의 범위를 벗어나는 연산 결과
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

vector<vector<string>> arr(101,vector<string>(101,"-1"));

class bigInteger {
public:
	string val;
	bigInteger(string b) {
		val = b;
	}
	bigInteger operator+ (bigInteger b) {
		string str = val;
		string sub = b.val;
		if (val.size() < b.val.size()) {
			str = b.val;
			sub = val;
		}
		bool carry = false;
		for (int i = sub.size()-1; i >=0; i--) {
			int num1 = str[str.size()-sub.size()+i] - '0';
			int num2 = sub[i] - '0';
			if (carry) {
				num1++;
				carry = false;
			}
			int sum = num1 + num2;
			if (sum > 9) {
				carry = true;
				sum -= 10;
			}
			str[str.size() - sub.size() + i] = sum + '0';
		}
		int idx = str.size() - sub.size() - 1;
		while (carry) {
			if (idx == -1) {
				str.insert(str.begin(),'1');
				break;
			}
			int num = str[idx] - '0';
			num++;
			if (num > 9) {
				num -= 10;
			}
			else
				carry = false;
			str[idx] = num + '0';
			idx--;
		}
		return str;
	}
};

bigInteger run(int a, int b) {
	if (b > a / 2)
		b = a - b;
	if (b == 1)	return bigInteger(to_string(a));
	if (b == 0)	return bigInteger("1");

	string& ret = arr[a][b];
	if (ret != "-1")
		return bigInteger(ret);
	bigInteger t = run(a - 1, b - 1) + run(a - 1, b);
	ret = t.val;
	return t;
}

void test() {
	int N, M;
	cin >> N >> M;
	if (N == M) {
		cout << 1;
		return;
	}
	if (M > N / 2)
		M = N - M;
	cout << (run(N - 1, M - 1) + run(N - 1, M)).val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
