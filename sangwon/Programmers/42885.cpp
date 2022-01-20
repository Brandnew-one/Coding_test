// 프로그래머스 [구명보트]
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    
    // 정렬을 하고 양끝을 살펴본다.
    // 최소 ---- 최대 형태이므로, 최소 + 최대가 기준을 넘는다면 최대는 보트를 혼자 타야한다.
    int start = 0, end = people.size() - 1;
    while(start <= end) {
        if(people[start] + people[end] > limit) {
            end--;
        } else {
            start++;
            end--;
        }
        answer++;
    }
    
    return answer;
}