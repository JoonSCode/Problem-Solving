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

int N, M;

void test() {
	cin >> N >> M;
	unordered_map<string, string> pw;
	for (int i = 0; i < N; i++) {
		string str, pwd;
		cin >> str >> pwd;
		pw.insert({ str,pwd });
	}
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		cout << pw.find(str)->second << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
