// [프로그래머스] 입국심사
// long long end = times[times.size() - 1] * (long long)n; 이부분 때문에 오류로 시간 너무 많이 씀.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 현재 주어진 시간에서 심사대를 몇 명 지나갈 수 있는가?
long long findN(long long ref, vector<int> times) {
    long long n = 0;
    for(int i = 0; i < times.size(); i++) {
        n += ref / times[i];
    }
    return n;
}

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    long long start = 0;
    long long end = times[times.size() - 1] * (long long)n;
    long long answer = end, mid = 0;
    
    while(start <= end) {
        mid = (start + end) / 2;
        long long temp = findN(mid, times);
        if(temp < n) {
            start = mid + 1;
        } else {
            if(mid <= answer) answer = mid;
            end = mid - 1;
        }
    }
    return answer;
}