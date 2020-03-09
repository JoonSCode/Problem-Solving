//Main idea: 1.버블소트의 제목을 가졌지만 실은 머지소트 2.머지소트를 잘 써야한다. 3. 머지소트 구현에도 
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int N;
long long answer = 0;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
}

void Merge(int start, long long mid, int end) {
    long long idx1 = start;
    long long idx2 = mid+1;
    vector<int> ans;

    while (idx1 <= mid && idx2 <= end) {
        if (arr[idx1] <= arr[idx2]) {
            ans.push_back(arr[idx1]);
            idx1++;
        }
        else {
            ans.push_back(arr[idx2]);
            idx2++;
            answer += (mid - idx1 + 1);
        }
    }
    if (idx1 <= mid) {
        for (idx1; idx1 <= mid; idx1++) 
            ans.push_back(arr[idx1]);
    }
    else {
        for (idx2; idx2 <= end; idx2++)
            ans.push_back(arr[idx2]);
    }
    for (int i = start; i <= end; i++)
        arr[i] = ans[i - start];
}

void MergeSort(int start, int end) {
    if (start < end) {
        long long mid = (start + end) / 2;
        MergeSort(start, mid);
        MergeSort(mid + 1, end);
        Merge(start, mid, end);
    }
}

void BubbleSort() {
    input();
    MergeSort(0, N-1);
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    BubbleSort();
}
