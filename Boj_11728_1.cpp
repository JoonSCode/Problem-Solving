//Main idea: 다 받아서 퀵소트로 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr;

void input() {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a + b; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
}

void SumArr() {
    input();
    sort(arr.begin(), arr.end());
    for (int i : arr)
        cout << i << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    SumArr();
}
