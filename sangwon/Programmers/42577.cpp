// [프로그래머스] 전화번호 목록

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

unordered_set<string> set;


// 초기풀이 : 시간초과
// bool cmp(string a, string b) {
//     if(a.size() >= b.size()) {
//         return false;
//     } else return true;
// }

// bool solution(vector<string> phone_book) {
//     bool answer = true;
//     sort(phone_book.begin(), phone_book.end(), cmp);
    
//     for(int i = 0; i < phone_book.size() - 1; i++) {
//         for(int j = i + 1; j < phone_book.size(); j++) {
//             // 전화번호 중복되지 않기 때문에 같은 길이는 비교할 필요x
//             if(phone_book[i].size() == phone_book[j].size())continue;
//             string temp = phone_book[j].substr(0, phone_book[i].size());
//             if(temp.find(phone_book[i]) != string::npos) {
//                 return false;
//             }
//         }
//     }
//     return answer;
// }


// 해시를 적용한 풀이
bool solution(vector<string> phone_book) {
    bool answer = true;
    for(int i = 0; i < phone_book.size(); i++) {
        set.insert(phone_book[i]);
    }
    for(int i = 0; i < phone_book.size(); i++) {
        for(int j = 0; j <= phone_book[i].size() - 1; j++) {
            string temp;
            if(j == 0) temp = phone_book[i][0];
            else {
                temp = phone_book[i].substr(0, j);
            }
            if(set.find(temp) != set.end()) return false;
        }
    }
    
    return answer;
}