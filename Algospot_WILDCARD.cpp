//Main idea: 1.*의 처리방법 2.
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<string> file_name;
string wild, norm;
int cache[101][101];//w_pos, n_pos일 때 결과 값
int N;

int isMatch(int w_pos, int n_pos) {
    int& ret = cache[w_pos][n_pos];
    if (ret != -1) return ret;
    if ( w_pos < wild.size() && n_pos < norm.size() && (wild[w_pos] == norm[n_pos] || (wild[w_pos] == '?'))) 
        return ret = isMatch(w_pos+1, n_pos+1);
    if (w_pos == wild.size()) return (n_pos == norm.size());//둘다 끝인경우면 일치하는 것
    if (wild[w_pos] == '*') {
        int tmp = 0;
        for (int i = n_pos; i <= norm.size(); i++) {//*하나당 n_pos 0부터 남은 것 전부까지 대응해봄 답인 경우가 하나라도 있으면 매칭 되는 것
            tmp = isMatch(w_pos + 1, i);
            if (tmp) return ret = tmp;
        }
        return ret = tmp;
    }
    return ret = 0;
}


void WildCard(){
    cin >> wild >> N;
    for (int i = 0; i < N; i++) {
        cin >> norm;
        memset(cache, -1, sizeof(cache));//dp위해 초기화
        if (isMatch(0, 0)) file_name.push_back(norm);
    }
    sort(file_name.begin(), file_name.end());//정렬
    for (string tmp : file_name)//출력
        cout << tmp << "\n";
}

void init() {
    file_name.clear();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        init();
        WildCard();
    }
}
