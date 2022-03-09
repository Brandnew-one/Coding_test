//[BOJ]1620 나는야 포켓몬 마스터 이다솜

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
string s;
unordered_map<string, int> map;
string arr[100002]; // 숫자는 counting sort 이용 (map 2개 써도 가능)

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        arr[i] = s;
        map[s] = i;
    }

    for(int i = 0; i < m; i++) {
        cin >> s;
        if(s[0] >= '0' && s[0] <= '9') {
            cout << arr[stoi(s)] << '\n';
        } else {
            cout << map[s] << '\n';
        }
    }


    return 0;
}