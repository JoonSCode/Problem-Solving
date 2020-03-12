//Main idea: 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
vector<int> arr;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
}

void ATM() {
    input();
    sort(arr.begin(), arr.end());
    int cost = 0;
    int sum = 0;
    for (int& a : arr) {
        cost += a;
        sum += cost;
    }

    cout << sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ATM();
}
