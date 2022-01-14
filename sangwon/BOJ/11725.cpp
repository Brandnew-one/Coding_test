//BOJ 11725(트리의 부모 찾기)
//256MB -> 0.6억개의 int (o)
//1초 -> O(N+N-1) (0)
#include <iostream>
#include <queue>
using namespace std;

int n;
int p[100002];
vector<int>adj[100002];

void bfs(){
    queue<int>Q;
    Q.push(1);
    while(!Q.empty()){
        int cur=Q.front();
        Q.pop();
        for(int i=0; i<adj[cur].size(); i++){
            int next=adj[cur][i];
            if(p[cur]==next)continue;
            Q.push(next);
            p[next]=cur;
        }
    }
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    for(int i=2; i<=n; i++){
        cout<<p[i]<<'\n';
    }

    return 0;
}