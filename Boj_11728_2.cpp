//Main idea:문제의 의도로 보이는 merge sort
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> arr1;
vector<int> arr2;

void input() {
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        int tmp;
        cin >> tmp;
        arr1.push_back(tmp);
    }
    for (int i = 0; i < b; i++) {
        int tmp;
        cin >> tmp;
        arr2.push_back(tmp);
    }
}

void mergeSort() {
    int idx1 = 0;
    int idx2 = 0;
    while(idx1 < arr1.size() && idx2 < arr2.size()) {
        if (arr1[idx1] <= arr2[idx2]) {
            cout << arr1[idx1] << " ";
            idx1++;
        }
        else {
            cout << arr2[idx2] << " ";
            idx2++;
        }
    }
    if (idx1 < arr1.size()) {
        for (idx1; idx1 < arr1.size(); idx1++)
            cout << arr1[idx1]<<" ";
    }
    else {
        for (idx2; idx2 < arr2.size(); idx2++)
            cout << arr2[idx2]<<" ";
    }
}

void SumArr() {
    input();
    mergeSort();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    SumArr();
}
