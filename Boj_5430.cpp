#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <utility>

using namespace std;

void solution() {
    string op;
    int sz;
    cin >> op >> sz;
    deque<int> li;
    string str;
    cin >> str;
    string tmp = "";
    for (int i = 1; i < str.size() - 1; i++) {
        if (str[i] == ',') {
            li.push_back(atoi(tmp.c_str()));
            tmp = "";
        }
        else
            tmp += str[i];
    }
    if(tmp != "")
        li.push_back(atoi(tmp.c_str()));
    bool isRev = false;
    for (char a : op) {
        if (a == 'R') isRev = !isRev;
        else if (li.size() == 0) {
            cout << "error\n";
            return;
        }
        else {
            if (isRev) 
                li.pop_back();
            else 
                li.pop_front();
        }
    }
    cout << "[";
    if (li.size() != 0) {
        if (isRev) {
            while (li.size() != 1) {
                cout << li.back() << ",";
                li.pop_back();
            }
            cout << li.front();
        }
        else {
            while (li.size() != 1) {
                cout << li.front() << ",";
                li.pop_front();
            }
            cout << li.front();
        }
    }
    cout << "]\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;
    while (T--)
        solution();
}
