//프로그래머스 [거리두기 확인하기] - 맨허튼거리를 굳이 생각할 필요없이 dist 로 각 거리를 계산하면 된다!
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

int vis[5][5];
int dy[4] = {-1, 1, 0 ,0};
int dx[4] = {0, 0, -1, 1};


// 응시자별로 bfs를 돌리니까 vis 초기화 시키는 함수
void reset_vis() {
    for(int y = 0; y < 5; y++) {
        for(int x = 0; x < 5; x++) vis[y][x] = 0;
    }
}

void show_vis() {
    for(int y = 0; y < 5; y++) {
        for(int x = 0; x < 5; x++) {
          cout << vis[y][x] << ' ';  
        } 
        cout << '\n';
    }
}

//현재풀이로 세번쨰 대기실 (4,4) - (2,2) 의 case 에서 오류발생
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    vector<pair<int,int>> p_position;
    
    for(int i = 0; i < 5; i++) {
        answer.push_back(1);
        
        //P 좌표들을 벡터에 저장
        for(int y = 0; y < 5 ; y++) {
            for(int x = 0; x < 5; x ++) {
                if(places[i][y][x] == 'P') p_position.push_back({y,x});
            }
        }
        
        while(!p_position.empty()) {
            queue<pair<int, int>> q;
            pair<int, int> p = p_position.back(); //현재 관찰하는 응시자
            p_position.pop_back();
            q.push(p);
            vis[p.first][p.second] = 1;
            bool flag = true;
            
            //현재 관찰하는 응시자를 기준으로 BFS
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir ++) {
                    int ny = cur.first + dy[dir];
                    int nx = cur.second + dx[dir];
                    if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5)continue;
                    if(vis[ny][nx])continue;
                    if(places[i][ny][nx] == 'X')continue;
                    if(places[i][ny][nx] == 'P' && vis[cur.first][cur.second] < 3) {
                        // cout << i + 1 << "번째 " << '\n';
                        // cout << "ny: " << ny << " nx: " << nx << '\n';
                        // cout << "y: " << p.first << " x: " << p.second << '\n';
                        flag = false;
                        break;
                    }
                    q.push({ny, nx});
                    vis[ny][nx] = vis[cur.first][cur.second] + 1;
                }
            }
            // show_vis();
            reset_vis();
            
            if(!flag) {
                answer.pop_back();
                answer.push_back(0);
                break;
            }
        }
        p_position.clear();
    }
    
    return answer;
}