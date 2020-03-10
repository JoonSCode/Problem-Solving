//Main idea: 이분탐색으로 해결(16번만에...!!!) -> 라인스위핑으로 다시 풀어볼 것
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<pair<int, int>> arr;
int N;


bool compare(const pair<int,int>& a, const pair<int,int>& b) {
    return a.second < b.second;
}

void input() {
    cin >> N;
    set<pair<int, int>>tmp;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        tmp.insert({ x,y });
    }
    for (pair<int, int> a : tmp)
        arr.push_back(a);
}

int dist(pair<int,int>& a, pair<int,int>& b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int run(int start, int end) {
    if (start + 2 == end) 
        return min(dist(arr[start], arr[start + 1]), min(dist(arr[start + 1], arr[end]), dist(arr[start], arr[end])));
    if (start + 1 == end)
        return dist(arr[start], arr[end]);

    int mid = (start + end) / 2;
    int D = min(run(start, mid), run(mid + 1, end));

    vector<pair<int,int>> tmp;

    for (int i = mid; i >= start; i--) {
        if ((arr[mid].first - arr[i].first) * (arr[mid].first - arr[i].first) > D)
            break;
        tmp.push_back(arr[i]);
    }
    for (int i = mid + 1; i <= end; i++) {
        if ((arr[i].first - arr[mid].first) * (arr[i].first - arr[mid].first) > D)
            break;
        tmp.push_back(arr[i]);
    }

    sort(tmp.begin(), tmp.end(), compare);

    for (int i = 0; i < tmp.size() - 1; i++) {
        for (int j = i + 1; j < tmp.size(); j++) {
            if ((tmp[i].second - tmp[j].second) * (tmp[i].second - tmp[j].second) > D)
                break;
            D = min(D, dist(tmp[i], tmp[j]));
        }
    }
    return D;
}

void CloseDot() {
    input();
    if (arr.size() == 1)
        cout << "0";
    else
        cout << run(0, arr.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    CloseDot();
}
