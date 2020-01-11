#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

void run(unordered_map<int, int>&, int&, int&);
bool isNew(unordered_map<int, int>&, int&);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	unordered_map<int, int> permutation;
	int A, P;
	cin >> A >> P;

	run(permutation, A, P);
}
void run(unordered_map<int, int>& permutation, int& A, int& P) {
	int num = A;
	
	if (isNew(permutation, num)) {
		int next = 0;
		permutation.insert({ num, permutation.size() + 1 });//key를 수, value를 순열의 몇번째인지로 저장

		while (num / 10) {
			next += pow(num % 10, P);
			num /= 10;
		}
		next += pow(num, P);

		run(permutation, next, P);//재귀로 실행
	}
	else {
		cout << permutation.find(num)->second - 1;
	}
}
bool isNew(unordered_map<int, int>& permutation, int& num) {//새로 맵에 들어오는 것인지 확인하는 함수
	auto it = permutation.find(num);
	if (it == permutation.end())
		return true;
	return false;
}
