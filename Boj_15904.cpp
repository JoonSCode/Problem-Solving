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

bool solution() {
    string str;
    getline(cin, str);
    bool a = true;
    int idx = 0;
    char arr[4] = { 'U','C','P','C' };
    for (char ch : arr) {
        idx = str.find(ch);
        if (idx == string::npos)
            return false;
        str = str.substr(idx + 1);
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    if (solution())
        cout << "I love UCPC";
    else
        cout << "I hate UCPC";
}
