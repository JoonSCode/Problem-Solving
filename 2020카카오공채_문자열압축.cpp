//Main idea:반복을 꾸준히 확인 하는 것
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Run(string s, int cutting_unit) {
    int size = 0;
    int repeat_cnt = 1;
    string first = "";
    string second = "";
    while (!s.empty()) {
        first = s.substr(0, cutting_unit);
        if (cutting_unit >= s.size()) {
            second = "";
            s = "";
        }
        else {
            second = s.substr(cutting_unit, cutting_unit);
            s = s.substr(cutting_unit);
        }

        if (first == second)//반복이 되는 경우
            repeat_cnt++;
        else if (repeat_cnt != 1) {//반복이 끝나는 경우
            size += to_string(repeat_cnt).size() + first.size();
            repeat_cnt = 1;
        }
        else {//반복이 안되는 경우
            size += first.size();
        }
    }
    return size;
}

int solution(string s) {
    int answer = 99999999;

    for (int i = 1; i <= (s.length() / 2) + 1; i++)
        answer = min(answer, Run(s, i));

    return answer;
}
