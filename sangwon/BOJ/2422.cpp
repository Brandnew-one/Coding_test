#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n,m,answer;
bool t[202][202];
vector <pair<int, int>> trash;
bool isused[202];

//200^3 * 10^4 = 8 * 10^10 => 시간초과..
void func(int cnt, int index) {
    if(cnt == 3) {
        bool flag = true;
        for(int i = 0; i < trash.size(); i++){
            int a = trash[i].first;
            int b = trash[i].second;
            if(isused[a] && isused[b]){
                flag = false;
                break;
            }
        }
        if(flag)answer++;
        return;
    }
    for(int i = index; i <= n; i++){
        if(isused[i])continue;
        isused[i] = true;
        func(cnt + 1, i + 1);
        isused[i] = false;
    }
}
/*
int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        pair<int, int> non;
        cin >> non.first >> non.second;
        trash.push_back(non);
    }
    func(0,1);
    cout << answer;

    return 0;
}
*/
int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int first, second;
        cin >> first >> second;
        t[first][second] = 1;
        t[second][first] = 1;
    }
    
    for(int i = 1; i <= n - 2; i++){
        for(int j = i + 1; j <= n - 1; j++){
            for(int k = j + 1; k <= n; k++){
                if(t[i][j] || t[i][k] || t[j][k])continue;
                answer++;
            }
        }
    }

    cout << answer;

    return 0;
}