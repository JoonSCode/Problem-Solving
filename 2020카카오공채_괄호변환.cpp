//Main_idea: 스택 개념을 이용하여 올바른 괄호 혹은 균형잡힌 괄호를 찾는 
#include <string>
#include <vector>

using namespace std;

string solution(string p) {
    string answer = "";
    string first_str = "";
    string second_str = "";

    int cnt = -1;
    bool is_correct_str = true;
    //초기값 설정
    if (p[0] == '(')
        cnt = 1;

    for (int i = 1; i < p.size(); i++) {
        if (cnt < 0)//닫힘이 먼저 나온경우는 올바르지 않음
            is_correct_str = false;

        if (p[i] == '(')//열고 닫음에 따라 값을 다르게 더한다.
            cnt++;
        else
            cnt--;
        if (cnt == 0) {
            first_str = p.substr(0, i + 1);
            second_str = p.substr(i + 1);
            break;
        }
    }

    if (is_correct_str) {// 첫 문자열이 올바른 문자열인 경우
        if(second_str !="")//뒤의 문자열도 있는 경우
            first_str += solution(second_str);

        answer = first_str;
    }
    else {
        if (second_str != "")
            answer += '(' + solution(second_str) + ')';
        else
            answer += "()";
        for (int i = 1; i < first_str.size() - 1; i++) {
            if (first_str[i] == '(')
                answer += ')';
            else
                answer += '(';
        }
    }
    return answer;
}
