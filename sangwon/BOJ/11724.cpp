//BOJ 11724(연결요소의 개수)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
int answer;
vector<int>adj[1002];
bool vis[1002];

void bfs(){
    queue<int>Q;
    for(int i=1; i<=N; i++){
        if(vis[i])continue;
        answer++;
        Q.push(i);
        vis[i]=1;
        while(!Q.empty()){
            int cur=Q.front();
            Q.pop();
            for(int j=0; j<adj[cur].size(); j++){
                int next=adj[cur][j];
                if(vis[next])continue;
                Q.push(next);
                vis[next]=1;
            }
        }
    }
}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>N>>M;
    for(int i=0; i<M; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    cout<<answer;

    return 0;
}