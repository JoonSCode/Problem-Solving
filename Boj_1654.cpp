//Main idea: 1.자료형의 범위 유의, 2.시작과 끝 범위 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> len_of_lan;
int K, N, big;

void input() {
    cin >> K >> N;
    big = 0;
    for (int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        len_of_lan.push_back(tmp);
        big = max(big, tmp);
    }
}

bool test(long long& num) {
    long long cnt = 0;
    for (int i : len_of_lan) {
        cnt += i / num;
        if (cnt >= N)//더 많이 만듬-> num을 키워야 함
            return true;
    }
    return false;//그만큼 못만듬 num을 줄여야함
}

int dq(long long start, long long end) {
    int ans = -1;
    while (start <= end) {
        long long mid = (end + start) / 2;
        if (test(mid)) {
            ans = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return ans;
}

void Lan() {
    input();
    cout << dq(1, big);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Lan();
}
