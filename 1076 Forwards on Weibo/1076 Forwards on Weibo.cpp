#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define N 1010


struct node {
    int id, level;
};
int n, l, k, m, t;
bool a[N][N], visit[N];

int bfs(int cur){
    fill(visit, visit+N, 0);
    visit[cur] = true;
    node t = node{cur, 0};
    queue<node> q;
    q.push(t);
    int cnt = 0;
    while(q.empty() == false){
        node top = q.front();
        q.pop();
        for(int i = 1; i <= n; i++){
            if(visit[i] == false && a[top.id][i] == true && top.level < l){
                node u = {i, top.level+1};
                q.push(u);
                visit[i] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void){
    cin>>n>>l;
    for(int i = 1; i <= n; i++){
        cin>>k;
        for(int j = 0; j < k; j++){
            cin>>t;
            a[t][i] = 1;
        }
    }
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>t;
        cout<<bfs(t)<<endl;
    }
}