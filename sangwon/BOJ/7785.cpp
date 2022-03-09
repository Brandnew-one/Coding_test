// BOJ7785(회사에 있는 사람)

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

int n;
unordered_set<string> set;
vector<string> answer;

bool cmp(string a, string b) {
    if(a >= b) return true;
    else return false;
}

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        string name, log;
        cin >> name >> log;
        if(log == "enter") set.insert(name);
        else set.erase(name);
    }
    // for(int i = 0; i < set.size(); i++) answer.push_back(set[i]);
    for(auto e : set)answer.push_back(e);
    sort(answer.begin(), answer.end(), cmp);

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }

    return 0;
}