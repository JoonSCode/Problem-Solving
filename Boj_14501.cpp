//Main idea: 특정 일자에서부터 최적 값 찾기
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dp(vector<pair<int,int>>& vec, int sum, int start) {//start에서부터 최고 이득
    int a = sum;
    int b = sum;
    if (start + 1 < vec.size())//오늘 일 안하고 내일로
        a = dp(vec, sum, start + 1);
    if (vec[start].first + start < vec.size())//오늘 일 하고 다음 일 가능한 날짜로 이동
        b = dp(vec, sum + vec[start].second, vec[start].first + start);
    else if (vec[start].first + start == vec.size())//오늘 일하고 이게 마지막
        b = sum + vec[start].second;
    return max(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<int, int>> vec;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back({ a,b });
    }
    cout<< dp(vec, 0, 0);
}
    
