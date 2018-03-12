#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0x3f3f3f3f
#define N 510
using namespace std;

int e[N][N], cost[N][N], mincost = INF, dis[N];
int n, m, s, d;
bool visit[N];
vector<int> pre[N];
vector<int> temppath, path;

void dfs(int v){
    temppath.push_back(v);
    if(v == s){
        int tempcost = 0;
        for(int i = temppath.size()-1; i > 0; i--){
            int id = temppath[i], nextid = temppath[i-1];
            tempcost += cost[id][nextid];
        }
        if(tempcost < mincost){
            mincost = tempcost;
            path = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++)
        dfs(pre[v][i]);
    temppath.pop_back();
}

int main(void){
    fill(e[0], e[0] + N*N, INF);
    fill(dis, dis + N, INF);
    cin>>n>>m>>s>>d;
    for(int i = 0; i < m; i++){
        int c1, c2, _dis, _cost;
        cin>>c1>>c2>>_dis>>_cost;
        e[c1][c2] = e[c2][c1] = _dis;
        cost[c1][c2] = cost[c2][c1] = _cost;
    }
    pre[s].push_back(s);
    dis[s] = 0;
    for(int i = 0; i < n; i++){
        int u = -1, minn = INF;
        // find minist distance.
        for(int j = 0; j < n; j++){
            if(visit[j] == false && dis[j] < minn)
                minn = dis[u = j];
        }
        if (u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++){
            if(visit[v] == false && e[u][v] != INF){
                if(dis[v] > dis[u] + e[u][v]){
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[v] == dis[u] + e[u][v]){
                    pre[v].push_back(u);
                }//else if
            }//if
        }//for
    }//for
    dfs(d);
    for(int i = path.size()-1; i >= 0; i--)
        cout<<path[i]<<" ";
    cout<<dis[d]<<" "<<mincost;
    return 0;
}//main