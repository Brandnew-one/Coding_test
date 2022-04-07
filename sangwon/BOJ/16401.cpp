//BOJ 16401(과자 나눠주기)
// 이분탐색을 이용한 log(10^9) * O(N) 풀이
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int M, N;
int answer;
vector<int> snack;

// L 길이를 M개를 만들 수 있는지 확인하는 함수 O(N)
bool isPossible(int l) {
    int cnt = 0;
    for(int i = 0; i < snack.size(); i++) {
        cnt += snack[i] / l;
    }
    if(cnt >= M)return true;
    else return false;
}

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        snack.push_back(num);
    }

    // 문제 조건이 L1 < L2 ... < Ln 을 만족한다고 생각해서 틀렸었음
    sort(snack.begin(), snack.end());

    int start = 1;
    int end = snack[snack.size() - 1];
    while(start <= end) {
        int mid = (start + end) / 2;
        if(isPossible(mid)) {
            answer = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << answer;

    return 0;
}