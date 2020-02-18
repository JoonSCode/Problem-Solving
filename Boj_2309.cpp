//Main idea: 초과값을 
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void find(vector<int>& tall) {
    int sum = 0;
    for (int a : tall)
        sum += a;
    sum -= 100;

    for (int i = 0; i <8; i++) {
        for (int n = i + 1; n < 9; n++) {
            if (tall[i] + tall[n] == sum) {
                tall.erase(tall.begin() + n);
                tall.erase(tall.begin() + i);
                break;
            }
        }
        if (tall.size() != 9)
            break;
    }
    sort(tall.begin(), tall.end());
    for (int a : tall)
        cout << a << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    vector<int> tall;
    int tmp = 0;
    for (int i = 0; i < 9; i++) {
        cin >> tmp;
        tall.push_back(tmp);
    }
    find(tall);
}
    
