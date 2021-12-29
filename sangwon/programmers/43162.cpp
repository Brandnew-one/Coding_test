//프로그래머스 [네트워크] - 이게 왜 LV3???? (LV2 보다 쉬웠던거 같음)
#include <string>
#include <queue>
#include <vector>

using namespace std;

int answer, cnt;
bool vis[102];

void bfs(vector<vector<int>> computers) {
    queue<int> q;
    for(int i = 0; i < cnt; i++) {
        if(vis[i])continue;
        q.push(i);
        answer++;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int j = 0; j < cnt; j++) {
                if(cur == j)continue; //computer[i][j] = 1
                if(computers[cur][j] == 0)continue;
                if(vis[j])continue;
                q.push(j);
                vis[j] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    cnt = computers[0].size();
    bfs(computers);
    return answer;
}