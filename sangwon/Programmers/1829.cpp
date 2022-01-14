#include <utility>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    int dy[4] = {-1, 1, 0 ,0};
    int dx[4] = {0, 0, -1, 1};
    
    //board, vis 초기화
    int board[102][102];
    bool vis[102][102];
    for(int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++) {
            board[y][x] = picture[y][x];
            vis[y][x] = false;
        }
    }
    
    int temp_size_of_one_area = 0;
    int temp_val = 0;
    queue<pair<int, int>> q;
    
    for(int y = 0; y < m; y++) {
        for(int x = 0; x < n; x++) {
            if(board[y][x] == 0 || vis[y][x] == true)continue;
            q.push({y, x});
            temp_val = board[y][x];
            vis[y][x] = 1;
            number_of_area++;
            temp_size_of_one_area++;
            while(!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++) {
                    int ny = cur.first + dy[dir];
                    int nx = cur.second + dx[dir];
                    if(ny < 0 || ny >= m || nx < 0 || nx >= n)continue;
                    if(vis[ny][nx] || board[ny][nx] != temp_val)continue;
                    vis[ny][nx] = true;
                    temp_size_of_one_area++;
                    q.push({ny, nx});
                }
            }
            if(temp_size_of_one_area >= max_size_of_one_area) {
                max_size_of_one_area = temp_size_of_one_area;
            }
            temp_size_of_one_area = 0;
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}