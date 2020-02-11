//Main idea: 어떻게 유효성 검사를 수행할 것인가.
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;


bool checkInstall(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order);
bool checkInstallPillar(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order);
bool checkInstallBeam(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order);
bool checkDel(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order);
bool checkDelPillar(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order);
bool checkDelBeam(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order);

bool compare(vector<int>& a, vector<int>& b){
    if(a[0] < b[0])
        return true;
    else if(a[0] == b[0]){
        if(a[1] < b[1])
            return true;
        else if(a[1] == b[1]){
            if(a[2] < b[2])
                return true;
            return false;
        }
        return false;
    }
    return false;
        
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    map<pair<int,int>, int> pillar_status;
    map<pair<int,int>, int> beam_status;

    for(vector<int> data: build_frame){
        if(data[3] == 1)//설치인 경우
            checkInstall(pillar_status, beam_status, data);
        else//삭제인 경우
            checkDel(pillar_status, beam_status, data);
    }
    
    for(pair<pair<int,int>, int> data: pillar_status)
        answer.push_back({data.first.first, data.first.second, 0});
    for(pair<pair<int,int>, int> data: beam_status)
        answer.push_back({data.first.first, data.first.second, 1});
    
    sort(answer.begin(), answer.end(), compare);
    
    return answer;
}
bool checkInstall(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order){
    if(order[2] == 0){
        if(checkInstallPillar(pillar_status, beam_status, order)){
            pillar_status.insert({{order[0], order[1]}, 1});
            return true;
        }
        else
            return false;
    }
    else{
        if(checkInstallBeam(pillar_status, beam_status, order)){
            beam_status.insert({{order[0], order[1]}, 1});
            return true;
        }
        else
           return false;
    }
}
bool checkInstallPillar(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order){
    int x = order[0];
    int y = order[1];
    if(y == 0)//바닥 위에 설치하는 경우
        return true;
    auto it = pillar_status.find({x,y-1});
    if(it != pillar_status.end())//아래 기둥 있는 경우
        return true;
    it = beam_status.find({x-1,y});
    if(it != beam_status.end())//왼쪽 보 있는 경우
        return true;
    it = beam_status.find({x,y});
    if(it != beam_status.end())//오른쪽 보 있는 경우
        return true;
    return false;
}
bool checkInstallBeam(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order){
    int x = order[0];
    int y = order[1];
    auto it = beam_status.find({x-1,y});
    auto it2 = beam_status.find({x+1,y});
    if(it != beam_status.end() && it2 != beam_status.end())//아래 기둥 있는 경우
        return true;
    it = pillar_status.find({x,y-1});
    if(it != pillar_status.end())//왼쪽 보 있는 경우
        return true;
    it = pillar_status.find({x + 1, y - 1});
    if(it != pillar_status.end())//오른쪽 보 있는 경우
        return true;
    return false;
}
bool checkDel(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order){
     if(order[2] == 0){
        if(checkDelPillar(pillar_status, beam_status, order)){
            auto it = pillar_status.find({order[0], order[1]});
            pillar_status.erase(it);
            return true;
        }
        else
            return false;
    }
    else{
        if(checkDelBeam(pillar_status, beam_status, order)){
            auto it = beam_status.find({order[0], order[1]});
            beam_status.erase(it);
            return true;
        }
        else
           return false;
    }
}
bool checkDelPillar(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order){
    int x = order[0];
    int y = order[1];
    map<pair<int,int>, int> new_pillar_status = pillar_status;
   
    new_pillar_status.erase({x,y});
         
    auto it = new_pillar_status.find({x, y + 1});
    vector<int> new_order{x, y + 1, 0, 1};
    if(it != new_pillar_status.end() && !checkInstallPillar(new_pillar_status, beam_status, new_order))//위에 기둥이 존재 할 수 없게 되는지 확인
        return false;
    
    it = beam_status.find({x - 1, y + 1});

    new_order = {x - 1, y + 1, 1, 1};

    if(it != beam_status.end() && !checkInstallBeam(new_pillar_status, beam_status, new_order))//왼쪽 보 확인
        return false;
    
    it = beam_status.find({x, y + 1});
    new_order = {x, y + 1, 1, 1};
    
    if(it != beam_status.end() && !checkInstallBeam(new_pillar_status, beam_status, new_order))//오른쪽 보 확인
        return false;    
    
    return true;
}
bool checkDelBeam(map<pair<int,int>, int>& pillar_status, map<pair<int,int>, int>& beam_status, vector<int>& order){
    int x = order[0];
    int y = order[1];
    map<pair<int,int>, int> new_beam_status = beam_status;
   
    new_beam_status.erase({x,y});
         
    auto it = new_beam_status.find({x - 1, y});
    vector<int> new_order{x - 1, y, 1, 1};
    if(it != new_beam_status.end() && !checkInstallBeam(pillar_status, new_beam_status, new_order))//위에 기둥이 존재 할 수 없게 되는지 확인
        return false;
    
    it = new_beam_status.find({x + 1, y});
    new_order = {x + 1, y, 1, 1};

    if(it != new_beam_status.end() && !checkInstallBeam(pillar_status, new_beam_status, new_order))//왼쪽 보 확인
        return false;
    
    it = pillar_status.find({x, y});
    new_order = {x, y, 0, 1};
    
    if(it != pillar_status.end() && !checkInstallPillar(pillar_status, new_beam_status, new_order))//오른쪽 보 확인
        return false;    
    
    it = pillar_status.find({x + 1, y});
    new_order = {x + 1, y, 0, 1};
    
    if(it != pillar_status.end() && !checkInstallPillar(pillar_status, new_beam_status, new_order))//오른쪽 보 확인
        return false;    
    
    return true;
}
