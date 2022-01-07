//프로그래머스[정수삼각형]
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int d[502][502];

int bigger(int a, int b) {
    if(a >= b) return a;
    else return b;
}

int solution(vector<vector<int>> triangle) {
    d[0][0] = triangle[0][0];
    for(int y = 1; y < triangle.size(); y++) {
        for(int x = 0; x < triangle[y].size(); x++) {
            // cout << "y's size :" << y << " x's size: " << x << '\n';
            if(x == 0) d[y][x] = d[y - 1][x] + triangle[y][x];
            else if (x == y) d[y][x] = d[y - 1][x - 1] + triangle[y][x];
            else d[y][x] = bigger(d[y - 1][x - 1], d[y - 1][x]) + triangle[y][x];
        }
    }
    
    // for(int y = 0; y < triangle.size(); y++) {
    //     for(int x = 0; x < triangle[y].size(); x++) {
    //         cout << d[y][x] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    int answer = 0;
    for(int x = 0 ; x < triangle.size(); x++) {
        if(d[triangle.size() - 1][x] >= answer) answer = d[triangle.size() - 1][x];
    }
    return answer;
}