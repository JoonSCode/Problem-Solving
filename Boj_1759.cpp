//Main idea: 글자의 길이가 길지 않으므로 2가지 경우로 나누어 수행한다.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
vector<string> answer;
vector<char> word;

void Input() {
	cin >> L >> C;
	char a;
	for (int i = 0; i < C; i++) {
		cin >> a;
		word.push_back(a);
	}
	sort(word.begin(), word.end());
}

void Run(string s, int idx, int v_cnt, int c_cnt) {//idx번째 단어를 고르는 경우 안고르는 경우로 나누어 탐색
	if (s.size() == L) {//원하는 길이가 된 경우 조건 만족 하는지 확인한다.
		if (v_cnt > 0 && c_cnt > 1) 
			answer.push_back(s);
		return;
	}
	if (idx >= C)//끝까지 이미 탐색한 경우 종료
		return;
	int is_v = 0;
	int is_c = 0;
	if (word[idx] == 'a' || word[idx] == 'e' || word[idx] == 'i' || word[idx] == 'o' || word[idx] == 'u')
		is_v = 1;
	else
		is_c = 1;
	Run(s + word[idx], idx + 1, v_cnt + is_v, c_cnt + is_c);
	Run(s, idx + 1, v_cnt, c_cnt);
}

void Pwd() {
	Input();
	Run("", 0, 0, 0);
	sort(answer.begin(), answer.end());
	for (string& a : answer)
		cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Pwd();
}
