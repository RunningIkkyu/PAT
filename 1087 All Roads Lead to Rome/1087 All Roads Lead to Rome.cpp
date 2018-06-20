#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define N 210
#define INF 0x3f3f3f
using namespace std;

int n, k, a[N][N], dis[N], w[N];
int maxvalue = 0, mindepth, cntpath = 0;
double maxavg;
bool visit[N];
map<string, int> ctoi;
map<int, string> itoc;
vector<int> pre[N], temppath, path;

void dfs(int v){
    temppath.push_back(v);
    if(v == 1){
        int value = 0;
        for(int i= 0; i < temppath.size(); i++){
            value += w[temppath[i]];
        }
        double tempavg = 1.0 * value /(temppath.size() - 1);
        if(value > maxvalue){
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;
        }
        else if(value == maxvalue && tempavg > maxavg){
            maxavg = tempavg;
            path = temppath;
        }
        temppath.pop_back();
        cntpath++;
        return;
    }
    for(int i = 0; i < pre[v].size(); i++){
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}

int main(void){
    fill(a[0], a[0]+N*N, INF);
    fill(dis, dis+N, INF);
    int t;
    string s, ss;
    cin>>n>>k>>s;
    ctoi[s] = 1;
    itoc[1] = s;
    for(int i = 2; i <= n; i++){
        cin>>s>>t;
        ctoi[s] = i;
        itoc[i] = s;
        w[i] = t;
    }
    for(int i = 0; i < k; i++){
        cin>>s>>ss>>t;
        int ind1 = ctoi[s];
        int ind2 = ctoi[ss];
        a[ind1][ind2] = a[ind2][ind1] = t;
    }
    dis[1] = 0;
    for(int j = 0; j < n; j++){
        int u = -1, minn = INF;
        for(int i = 1; i <= n; i++){
            if(visit[i] == false && dis[i] < minn){
                u = i;
                minn = dis[i];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int i = 1; i <=n; i++){
            if(visit[i] == false && a[u][i] != INF){
                if(dis[i] > dis[u] + a[u][i]){
                    dis[i] = dis[u] + a[u][i];
                    pre[i].clear();
                    pre[i].push_back(u);
                }
                else if(dis[i] == dis[u] + a[u][i]){
                    pre[i].push_back(u);
                }
            }
        }
    }
    int rom = ctoi["ROM"];
    dfs(rom);
    cout<<cntpath<<" "<<dis[rom]<<" "<<maxvalue<<" "<<(int)maxavg<<endl;
    for(int i = path.size()-1; i >= 1; i--){
        cout<<itoc[path[i]]<<"->";
    }
    cout<<"ROM"<<endl;
    return 0;
}