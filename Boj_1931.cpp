//Main idea: 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Conf {
    int start;
    int end;
    Conf(int a, int b) {
        start = a;
        end = b;
    }
};
int N;
vector<Conf> arr;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(Conf(a, b));
    }
}

bool cmp(const Conf& a, const Conf& b) {//끝나는 시간이 빠른게 중요하므로 end를 기준으로 정렬한다.
    if (a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}

void Conference() {
    input();
    sort(arr.begin(), arr.end(), cmp);
    int cnt = 0;
    int now = 0;
    for (Conf& a : arr) {
        if (a.start >= now) {
            cnt++;
            now = a.end;
        }
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    Conference();
}
