#include <cstdio>
#include <algorithm>
#define N 10010
using namespace std;

int v[N][N], n, a, b, components = 0, depth[N], maxdepth = 0;
bool visited[N];

void dfs(int s, int index, int d){
    visited[index] = true;
    if(d > depth[s]) depth[s] = d;
    for(int j = 1; j <= n; j++)
        if(v[index][j] == 1 && visited[j] == false) dfs(s, j, d+1);
}

int main(void)
{
    fill(v[0], v[0] + N * N, 0);
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(visited[i] == false){
            dfs(i, i, 1);
            components++;
        }
    }
    if(components > 1){
        printf("Error: %d components", components);
        return 0;
    }
    fill(depth, depth+N, 0);
    for(int i = 1; i <= n; i++){
        fill(visited, visited + N, 0);
        dfs(i, i, 1);
    }
    for(int i = 1; i <= n; i++){
        if(maxdepth < depth[i]) maxdepth = depth[i];
        maxdepth = max(maxdepth, depth[i]);
    }
    for(int i = 1; i <= n; i++){
        if(depth[i] == maxdepth) printf("%d\n", i);
    }
    return 0;
}