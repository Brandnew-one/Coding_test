//프로그래머스 열쇠와 자물쇠
//[문제링크] https://programmers.co.kr/learn/courses/30/lessons/60059
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int board[60][60], board_temp[60][60];
int m,n;

//시계방향 90도 회전 구현
void rotate_arr(vector<vector<int>>& key) {
    int temp[60][60];
    for(int y = 0; y < m; y++)
        for(int x = 0; x < m; x++)
            temp[x][m - 1 - y] = key[y][x];
    
    for(int y = 0; y < m; y++)
        for(int x = 0; x < m; x++)
            key[y][x] = temp[y][x];
}

bool isPossible() {
    for(int y = m - 1; y < m + n - 1; y++)
        for(int x = m - 1; x < m + n - 1; x++)
            if(board_temp[y][x] != 1)
                return false;
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    m = key.size();
    n = lock.size();
    
    for(int y = m - 1; y < m + n - 1; y++)
        for(int x = m - 1; x < m + n - 1; x++)board[y][x] = lock[y - m + 1][x - m + 1];
        
    bool answer = false;
    for(int dir = 0; dir < 4; dir ++) {    
        rotate_arr(key);
        for(int y = 0; y < m + n - 1; y++){
            for(int x = 0; x < m + n - 1; x++){
                
                //board_temp 초기화!
                for(int y = 0; y < n + 2 * m - 2; y++)
                    for(int x = 0; x < n + 2 * m - 2; x++)
                        board_temp[y][x] = board[y][x];
                
                //board_temp에 key 값들을 더해봄
                for(int yy = y; yy < y + m; yy++){
                    for(int xx = x; xx < x + m; xx++){
                        board_temp[yy][xx] += key[yy - y][xx - x];        
                    }
                }
                /*
                cout << "-----------------------\n";
                for(int y = 0; y < n + 2 * m - 2; y++){
                    for(int x = 0; x < n + 2 * m - 2; x++){
                        cout << board_temp[y][x] << ' ';
                    }
                    cout << '\n';
                }
                */
                if(isPossible())return true;
            }
        }
    }
    return answer;
}