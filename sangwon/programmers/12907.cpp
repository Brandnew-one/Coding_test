// 프로그래머스[거스름돈] - 다시 풀어보기!
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int d[100002];

int solution(int n, vector<int> money) {
    int answer = 0;
    sort(money.begin(), money.end()); // 돈의 종류가 오름차순으로 오지 않을 경우
    
    d[0] = 1; // 초기값 설정
    for(int i = money[0]; i <= n; i += money[0]) {
        d[i] = 1;
    }
    
    for(int i = 1; i < money.size(); i++) {
        for(int j = money[i]; j <= n; j++) {
            d[j] += d[j - money[i]] % 1000000007;
        }
    }
    
    return d[n];
}