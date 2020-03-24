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

using namespace std;

bool cmp(string a, string& b) {
	sort(b.begin(), b.end());
	int idx = a.size() - 1;

	while (idx != -1) {
		char tmp = a[idx];
		auto it = b.find_last_of(tmp);
		int cnt = 0;
		idx--;
		if (it == string::npos) 
			continue;
		a.erase(idx+1,1);
		b.erase(it,1);
	}
	int asz = a.size();
	int bsz = b.size();
	if (asz-bsz<-1 || asz-bsz>1)
		return false;
	if (asz > 1 || bsz > 1)
		return false;
	return true;
}

void Line() {
	int N;
	int ans = 0;
	string str;
	string org;
	vector<string> vec;
	
	cin >> N;
	cin >> org;
	sort(org.begin(), org.end());
	for (int i = 1; i < N; i++) {
		cin >> str;
		if (cmp(org, str))
			ans++;
	}
	cout<<ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Line();
}
