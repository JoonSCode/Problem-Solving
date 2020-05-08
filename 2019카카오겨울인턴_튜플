//Main idea: 갯수 적은 것 위치에 의존성 있음
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& a, const string& b) {
	return a.size() < b.size();
}

vector<int> solution(string str) {
	vector<int> answer;
	vector<string> vec;
	int arr[100001]{ 0, };
	bool start = false;
	for (int i = 1; i < str.size() - 1; i++) {//값 단위로자른다
		if ((str[i] == '{' && str[i + 1] == '{') || str[i] == '}') continue;
		if (str[i] == '{' && str[i + 1] != '{') {
			vec.push_back("");
			continue;
		}
		if (str[i] == ',' && str[i + 1] == '{') continue;
		vec.back() += str[i];
	}
	sort(vec.begin(), vec.end(), cmp);
	for (string s : vec) {
		while (s.find(',') != string::npos) {
			string a = s.substr(0, s.find(','));//숫자로 분리
			s = s.substr(s.find(',') + 1);
			int num = atoi(a.c_str());
			if (arr[num]) continue;
			answer.push_back(num);
			arr[num] = 1;
			continue;
		}
		int num = atoi(s.c_str());
		if (arr[num]) continue;
		answer.push_back(num);
		arr[num] = 1;
	}
	return answer;
}
