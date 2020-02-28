//Main idea: 1. 답의 범위가 int의 범위보다 클 수 있다. 2. 분할한 곳에 걸치는 경우가 있을 수 있다. 3. 알고리즘 문제 해결전략 책 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> arr;

long long histogram(int start, int end){
    long long ans = 0;
    if (start == end)//base case
        return arr[start];
    
    int mid = start + (end - start) / 2;//분할한 것들중 최대 값
    ans = max(ans, histogram(start, mid));
    ans = max(ans, histogram(mid + 1, end));

    int a = mid;
    int b = mid + 1;
    long long h = min(arr[a], arr[b]);
    ans = max(ans, h * 2);//분할한 곳을 가로지르는 경우 너비2로 시작

    while (start < a || b < end) {
        if (b < end  && (start == a || arr[a - 1] < arr[b + 1])) {//왼쪽이 끝에 도달 혹은 왼쪽의 높이 보다 오른쪽의 높이가 큰 경우
            b++;
            h = min(arr[b], h);
        }
        else {
            a--;
            h = min(arr[a], h);
        }
        ans = max(ans, h * (b - a + 1));
    }
    return ans;
}

void input(int& N) {//입력
    long long tmp;
    arr.clear();
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        arr.push_back(tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    while (1) {
        cin >> T;
        if (T == 0)
            break;
        input(T);
        cout<<histogram(0,T-1)<<"\n";
    }

}
