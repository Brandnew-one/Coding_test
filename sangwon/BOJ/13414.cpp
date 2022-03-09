// [BOJ]13414 - 수강신청

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int k, l;
unordered_map<string, int> map;
vector<pair<int, string>> v;
string s;

int main(void) {

    cin >> k >> l;
    for(int i = 0; i < l; i++) {
        cin >> s;
        map[s] = i;
    }

    for(auto e : map) {
        v.push_back({e.second, e.first});
    }

    sort(v.begin(), v.end());

    if(v.size() >= k) {
        for(int i = 0; i < k; i++) {
            cout << v[i].second << '\n';
        }
    } else {
        for(int i = 0; i < v.size(); i++) {
            cout << v[i].second << '\n';
        }
    }

    return 0;
}