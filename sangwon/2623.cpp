//BOJ 2623(음악프로그램)
//128MB -> 0.3x10^8 int (o)
//1s -> O(V+E) (o)
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int indeg[1002];
vector<int>adj[1002];

void topo_sort(){
    queue<int>q;
    vector<int>result;
    for(int i=1; i<=n; i++){
        if(indeg[i]==0)q.push(i);
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        result.push_back(cur);
        for(int i=0; i<adj[cur].size(); i++){
            int next=adj[cur][i];
            indeg[next]--;
            if(indeg[next]==0)q.push(next);
        }
    }
    if(result.size()!=n){
        cout<<'0';
        return;
    }
    for(int i=0; i<n; i++)cout<<result[i]<<'\n';
}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0; i<m; i++){
        int cnt,a;
        cin>>cnt;
        vector<int>temp;
        for(int j=0; j<cnt; j++){
            cin>>a;
            temp.push_back(a);
        }
        for(int j=0; j<cnt-1; j++){
            adj[temp[j]].push_back(temp[j+1]);
            indeg[temp[j+1]]++;
        }
    }
    topo_sort();
    return 0;
}