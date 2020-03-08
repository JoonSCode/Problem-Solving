//Main idea: bs여러번 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> card;
vector<int> q;

int N, M;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        card.push_back(tmp);
    }
    sort(card.begin(), card.end());
}

int bs1(int start, int end, int& target) {//target값을 가지는 것 중 가장 큰 idx찾는것
    int ans = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (card[mid] > target)
            end = mid - 1;
        else if (card[mid] == target) {
            start = mid + 1;
            ans = mid;
        }
        else 
            start = mid + 1;
    }
    return ans;
}

int bs2(int start, int end, int& target) {//target값을 가지는 것 중 가장 작은 idx찾는것
    int ans = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (card[mid] > target) 
            end = mid - 1;
        else if (card[mid] == target) {
            end = mid - 1;
            ans = mid;
        }
        else
            start = mid + 1;    
    }
    return ans;
}

void run(int i) {
    int s = bs1(0, N - 1, i);
    if (s == -1)
        cout << "0 ";
    else
        cout << s - bs2(0, s, i) + 1 << " ";
}

void NumCard() {
    input();
    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        run(tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    NumCard();
}
