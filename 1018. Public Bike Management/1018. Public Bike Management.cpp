#include <cstdio>
#include <algorithm>
#include <vector>
#define N 510
#define INF 0x3f3f3f3f
using namespace std;

int bike[N];
int dist[N];
int e[N][N];
int minNeed = INF, minBack = INF;
int cmax, n, sp, m, a, b, t;
bool visited[N];
vector<int> pre[N];
vector<int> path, temppath;

void dfs(int v) {
    temppath.push_back(v);
    if(v == 0) {
        int need = 0, back = 0;
        for(int i = temppath.size() - 1; i >= 0; i--) {
            int id = temppath[i];
            if(bike[id] > 0) {
                back += bike[id];
            } else {
                if(back > (0 - bike[id])) {
                    back += bike[id];
                } else {
                    need += ((0 - bike[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minNeed) {
            minNeed = need;
            minBack = back;
            path = temppath;
        } else if(need == minNeed && back < minBack) {
            minBack = back;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}


int main(void)
{
    fill(e[0], e[0] + N*N, INF);
    scanf("%d%d%d%d", &cmax, &n, &sp, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &bike[i]);
        bike[i] = bike[i] - cmax / 2;
    }
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &t);
        e[a][b] =t;
        e[b][a] = t;
    }
    // initiation of dijkstra's algorithm.
    fill(dist, dist + N, INF);
    fill(visited, visited + N, 0);
    dist[0] = 0;

    for(int j = 0; j <= n; j++){
        int u = -1;           //the index of the element with minimum distance from source point.
        int minn = INF;  
        for(int i = 0; i <= n ; i++){
            if(visited[i] == false && dist[u] < minn){
                minn = dist[i];
                u = i;
            }
        }
        if(u == -1) break;
        visited[u] = true;
        // for all the neighbor of u do relax.
        for(int i = 0; i <= n; i++){
            if(visited[i] == false && e[u][i] != INF){
                if(dist[i] > dist[u] + e[u][i]){
                    dist[i] = dist[u] + e[u][i];
                    pre[i].clear();
                    pre[i].push_back(u);
                }else if (dist[i] == dist[u] + e[u][i]){
                    pre[i].push_back(u);
                }
            }
        }
    }
    dfs(sp);
    printf("%d 0", minNeed);
    for(int i = path.size()-2; i >= 0; i--) printf("->%d", path[i]);
    printf(" %d", minBack);
    return 0;
}