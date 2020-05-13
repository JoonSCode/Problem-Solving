//Main idea: map을 이용해서 색인 시뮬레이션
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> map;
    int idx = 27;

    string a = "A";
    for (int i = 0; i < 26; i++) {//색인 초기화
        map.insert({ a,i + 1 });
        a[0] += 1;
    }
    for (int i = 0; i < msg.size(); i++) {
        string str = "";
        str += msg[i];
        auto it = map.find(str);
        while (it != map.end()) {//색인 없을 때 까지 탐색
            i++;
            str += msg[i];
            it = map.find(str);
        }

        i--;
        map.insert({ str, idx });
        str.pop_back();
        answer.push_back(map.find(str)->second);
        idx++;
    }
    return answer;
}
