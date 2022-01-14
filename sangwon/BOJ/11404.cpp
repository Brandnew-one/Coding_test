//BOJ 11404(플로이드)
#include <iostream>
#include <vector>
using namespace std;

int n,m;
int d[102][102];
//vector <pair<int, int>> adj[102]; //node, cost

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> m;
    //2개 값 더했을때 overflow 방지 -> 10억으로 max값 설정
    for(int y = 1; y <= n; y++)
        for(int x = 1; x <=n; x++)d[y][x] = 1000000000;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        //adj[a].push_back({b, c});
        if(d[a][b] < c)continue;
        d[a][b] = c;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(d[i][j] >= d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)d[i][i] = 0;

    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= n; x++){
            if(d[y][x] == 1000000000)cout<<"0 ";
            else cout<<d[y][x]<<' ';
        }
        cout<<'\n';
    }
    

    return 0;
}
