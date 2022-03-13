// 프로그래머스 [신고 결과 받기]

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<string, int> countMap;
unordered_map<string, unordered_set<string>> map;

void setHashMap(vector<string> id_list, vector<string> report) {
    for(int i = 0; i <id_list.size(); i++) {
        countMap[id_list[i]] = 0; // 신고횟수 0으로 hashMap 생성
    }
    
    for(int i = 0; i < report.size(); i++) {
        string fUser, sUser;
        int index = report[i].find(' ');
        fUser = report[i].substr(0, index);
        sUser = report[i].substr(index);
        if(map[fUser].find(sUser) == map[fUser].end()) {
            countMap[sUser] += 1; // 신고횟수 증가
            map[fUser].insert(sUser);
        }
    }
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    setHashMap(id_list, report);
    vector<int> answer;
    for(int i = 0; i < id_list.size(); i++) {
        int cnt = 0;
        for(auto e : map[id_list[i]]) {
            if(countMap[e] >= k)cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}