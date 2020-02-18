//Main idea: divide & conquer + 좌표 
#include <iostream>
#include <cmath>
using namespace std;

int run(int N, int r, int c) {
	if (N == 1)
		return r*2 + c;

	if (pow(2, N) / 2 > r) {//위쪽 인 경우
		if (pow(2, N) / 2 > c) {//왼쪽 위
			return run(N - 1, r, c);
		}
		else {//오른쪽 위
			c -= (pow(2, N) / 2);
			return pow(2, 2 * (N - 1)) + run(N - 1, r, c);
		}
	}
	else {
		r -= pow(2, N) / 2;
		if (pow(2, N) / 2 > c) {//왼쪽 아래
			return pow(2, 2*N - 1) + run(N - 1, r, c);
		}
		else {//오른쪽 아래
			c -= (pow(2, N) / 2);
			return pow(2, 2 * (N-1))* 3 + run(N - 1, r, c);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	int N, r, c;
	cin >> N >> r >> c;
	cout  << run(N,r,c);
 }
