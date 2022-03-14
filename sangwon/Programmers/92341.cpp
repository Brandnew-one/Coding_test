// [프로그래머스] 주차 요금 계산

#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

unordered_map<string, int> map;
unordered_map<string, string> inOut;
vector<pair <string, int>> v;

// 문자열을 시간, 차, 입/출차 기준으로 나눠주는 함수
tuple<string, string, string> splitString(string record) {
    
    int firstIndex, secondIndex;
    firstIndex = record.find(' ');
    secondIndex = record.find(' ', firstIndex + 1);
    
    string time, car, mode;
    time = record.substr(0, firstIndex);
    car = record.substr(firstIndex + 1, secondIndex - firstIndex);
    mode = record.substr(secondIndex + 1);
    
    return make_tuple(time, car, mode);
}

// 해쉬맵을 초기화 해주는 함수
void setHashMap(vector<string> records) {
    for(int i = 0; i < records.size(); i++) {
        tuple<string, string, string> s = splitString(records[i]);
        map[get<1>(s)] = 0;
    }
}

// 입, 출차 시간을 기준으로 분단위 시간을 계산하는 함수
int calTime(string in, string out) {
    int inH, inM, outH, outM;
    inH = stoi(in.substr(0, 2));
    inM = stoi(in.substr(3, 2));
    outH = stoi(out.substr(0, 2));
    outM = stoi(out.substr(3, 2));
    return (outH - inH) * 60 + (outM - inM);
}

// 시간을 기준으로 요금을 계산하는 함수
int calMoney(int time, vector<int> fees) {
    if(time <= fees[0]) {
        return fees[1];
    } else {
        int remainTime = time - fees[0];
        int unitTimes = remainTime / fees[2];
        if(remainTime % fees[2] != 0)unitTimes += 1;
        return (unitTimes * fees[3]) + fees[1];
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    setHashMap(records);
    for(int i = 0; i < records.size(); i++) {
        tuple<string, string, string> s = splitString(records[i]);
        if(get<2>(s) == "IN") {
            inOut[get<1>(s)] = get<0>(s);
        } else { // OUT 인 경우
            map[get<1>(s)] += calTime(inOut[get<1>(s)], get<0>(s));
            inOut[get<1>(s)] = "";
        }
    }
    // 다 돌고 난후에 출차하지 않은 경우에는 23:59 기준으로 출차를 시켜준다.
    for(auto e : inOut) {
        if(e.second != "") {
            map[e.first] += calTime(e.second, "23:59");
            inOut[e.first] = "";
        }
    }
    for(auto e : map) {
        // cout << e.first << ": " << e.second << '\n';
        int money = calMoney(e.second, fees);
        v.push_back({e.first, money});
    }
    sort(v.begin(), v.end());
    
    vector<int> answer;
    for(int i = 0; i < v.size(); i++) {
        // cout << v[i].first << ": " << v[i].second << '\n';
        answer.push_back(v[i].second);
    }
    
    return answer;
}