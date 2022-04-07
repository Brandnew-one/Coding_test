// BOJ 2805(나무 자르기)
// 2*10^9이 최대값이니까 Int형으로 충분이 풀이 가능!
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int answer;
vector<int> tree;

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        tree.push_back(num);
    }

    int start = 1;
    int end = 2000000000;

    while(start <= end) {
        int mid = (start + end) / 2;
        long long temp = 0;
        for(int i = 0; i < tree.size(); i++) {
            if(tree[i] > mid) temp += tree[i] - mid;
        }
        if(temp < M) {
            end = mid - 1;
        } else {
            answer = mid;
            start = mid + 1;
        }
    }

    cout << answer;

    return 0;
}

