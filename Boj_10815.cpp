//Main idea: 단순 
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
    cin >> M;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        q.push_back(tmp);
    }
    sort(card.begin(), card.end());
}

bool bs(int start, int end, int& target) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (card[mid] > target)
            end = mid - 1;
        else if (card[mid] == target)
            return true;
        else
            start = mid + 1;    
    }
    return false;
}

void run() {
    for (int i : q) {
        if (bs(0, N - 1, i))
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
}

void NumCard() {
    input();
    run();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    NumCard();
}
