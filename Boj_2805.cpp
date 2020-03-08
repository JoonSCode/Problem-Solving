//Main idea: 1. 자료형의 범위 주의하기(mid를 만들 때)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tree;
int N, M, big;

void input() {
    cin >> N >> M;
    big = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        tree.push_back(tmp);
        big = max(big, tmp);
    }
}

int cut(long long& num) {
    long long cnt = 0;
    for (int i : tree) {
        if(i > num)
            cnt += i - num;
        if (cnt > M)//나무를 너무 많이 가져감 -> num을 키워야 함
            return 1;
    }
    if(cnt == M)
        return 2;
    return 3;//나무가 더 필요함 -> num을 줄여야함
}

int bs(long long start, long long end) {
    int ans = -1;
    while (start <= end) {
        long long mid = (start + end) / 2;
        int result = cut(mid);
        if (result == 1) {
            ans = mid;
            start = mid + 1;
        }
        else if (result == 2) {
            ans = mid;
            break;
        }
        else 
            end = mid - 1;
    }
    return ans;
}

void CutTree() {
    input();
    cout << bs(0, big);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    CutTree();
}
