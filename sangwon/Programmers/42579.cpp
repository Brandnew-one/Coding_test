// 프로그래머스[베스트앨범]
// 해시를 이용해서 구현 난이도를 줄여보자!

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

vector<pair <string, pair<int, int> > > v; // 장르, 재생횟수, 고유번호
vector<pair <int, string>> p; // 총 재생횟수, 장르

bool cmp(pair<int, string>a, pair<int, string>b) {
    if(a.first > b.first)return true;
    else return false;
}

void countGenres() {
    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        if(p.empty()) p.push_back({v[i].second.first, v[i].first});
        else {
            if(v[i].first == p[cnt].second) {
                p[cnt].first += v[i].second.first;
            } else {
                cnt += 1;
                p.push_back({v[i].second.first, v[i].first});
            }
        }
    }
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    for(int i = 0; i < genres.size(); i++) {
        v.push_back({genres[i], {plays[i], i}});
    }

    sort(v.begin(), v.end());
    // for(int i = 0; i < v.size(); i++) {
    //     cout << v[i].first << " " << v[i].second.first << '\n';
    // }
    countGenres();
    sort(p.begin(), p.end(), cmp);

    vector<int> answer;
    for(int i = 0; i < p.size(); i++) {
        string ref = p[i].second;
        int indexMin = 0, indexMax = 0;
        for(; v[indexMin].first != ref; indexMin++);
        for(indexMax = indexMin; v[indexMax].first == ref && indexMax < v.size(); indexMax++);
        indexMax -= 1;
        if(indexMax == indexMin) { // 장르에 속한 곡이 하나인 경우
            answer.push_back(v[indexMin].second.second);
        } else { // 재생횟수가 많은 경우 그냥 역순으로 넣어주면 되고
            if(v[indexMax].second.first > v[indexMax - 1].second.first) {
                answer.push_back(v[indexMax].second.second);
                answer.push_back(v[indexMax - 1].second.second);
            } else { // 재생횟수가 같은 경우에는 고유번호가 낮은걸 우선순위로 넣어준다.
               if(v[indexMax].second.second > v[indexMax - 1].second.second) {
                    answer.push_back(v[indexMax - 1].second.second);
                    answer.push_back(v[indexMax].second.second);
               } else {
                    answer.push_back(v[indexMax - 1].second.second);
                    answer.push_back(v[indexMax].second.second);
               }
            }
        }
    }

    return answer;
}