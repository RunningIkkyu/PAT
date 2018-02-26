#include <iostream>
#include <algorithm>
#define N 1010
using namespace std;

int city[N][N];
int visited[N];
int n, m, k, x, c1, c2, component;

void dfs(int cur){
    visited[cur] = 1;
    for(int i = 1; i <= n; i++)
        if(visited[i] == 0 && city[cur][i] == 1) dfs(i);

}

int main(void)
{
    fill(city[0], city[0]+N*N, 0);
    cin>>n>>m>>k;
    for(int i = 0; i < m; i++){
        cin>>c1>>c2;
        city[c1][c2] = city[c2][c1] = 1;
    }
    for(int j = 0; j < k; j++){
        fill(visited, visited+N, 0);
        cin>>x;
        component = 0;
        visited[x] = 1;
        for(int i = 1; i <= n; i++){
            if(visited[i] == 0){
                dfs(i);
                component++;
            }
        }
        cout<<component-1<<endl;
    }
    return 0;
}