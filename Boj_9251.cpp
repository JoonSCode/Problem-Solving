//Main idea: 테이블을 이용한 LCS 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string N, K;
vector<vector<int>> cache;

void Lcs(){
    cin >> N >> K;
    cache.resize(N.size() + 1, vector<int>(K.size() + 1, 0));
    int ans = 0;
    for (int i = 1; i <= N.size(); i++) {//LCS알고리즘 이용
        for (int n = 1; n <= K.size(); n++) {
            if (N[i - 1] == K[n - 1])
                cache[i][n] = cache[i - 1][n - 1] + 1;
            else
                cache[i][n] = max(cache[i - 1][n], cache[i][n - 1]);
            ans = max(ans, cache[i][n]);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Lcs();
}
