//Main idea: 효과적으로 IOI갯수 세기
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <utility>

using namespace std;

void test() {
	int N, K;
	int answer = 0;
	string str;
	string a = "I";
	
	cin >> N >> K;
	cin >> str;
	
	for (int i = 0; i < N; i++)
		a += "OI";
	bool start = false;
	int size = 0;
	for (int i = 0; i < K; i++) {//앞에 I가 있을 때 뒤에 오는OI의 갯수를 센다.
		char val = str[i];
		if (!start) {//I로 시작하지 않고 있는 경우
			if (val == 'I')
				start = true;
			continue;
		}
		if (val != str[i - 1]) {//IO,OI확인
			if (val == 'I')	size++;//OI이면 size+1
		}
		else {
			if(val == 'O')//OIOO인경우 I가 앞에있는 상황이 아니므로 
				start = false;
			if (size >= N)//size-N+1만큼 만들 수 있음
				answer += size - N + 1;
			size = 0;
		}
	}
	if (size >= N)//맨 끝에서 마무리 되는 경우
		answer += size - N + 1;
	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	test();
}
