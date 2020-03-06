//Main idea: 1. 효율적 비교를 위한 정렬 2. 숫자의 범위 3. 끝날 때도 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<long long> card_input;

void input() {
    cin >> N;
    long long tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        card_input.push_back(tmp);
    }
    sort(card_input.begin(), card_input.end());
}

void Card(){
    input();
    long long tmp;
    int max_cnt = 0;
    int cur_cnt = 0;
    long long ans = 0;
    long long before = 0;
    for (int i = 0; i < N; i++) {
        tmp = card_input[i];
        if (tmp != before) {
            if (max_cnt < cur_cnt) {
                max_cnt = cur_cnt;
                ans = before;
            }
            cur_cnt = 1;
            before = tmp;
        }
        else 
            cur_cnt++;          
    }
    if (max_cnt < cur_cnt) {
        max_cnt = cur_cnt;
        ans = before;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Card();
}
