#include <iostream>
#include <cmath>
#include <vector>
#define N 100010
using namespace std;

int n, t, root, cnt;
double maxdepth, p, r;
vector<int> v[N];
bool visit[N];

void dfs(int index, int depth){
    visit[index] = true;
    if(depth > maxdepth){
        maxdepth = depth;
        cnt = 1;
    } else if(depth == maxdepth){cnt++;}
    for(int i = 0; i < v[index].size(); i++){
        if(visit[v[index][i]] == false) dfs(v[index][i], depth+1);
    }
}

int main(void){
    cin>>n>>p>>r;
    for(int i = 0; i < n; i++){
        cin>>t;
        if(t == -1) root = i;
        else 
            v[t].push_back(i);
    }
    dfs(root, 0);
    printf("%.2f %d\n",p * pow((1.0+r/100), maxdepth), cnt);
    return 0;
}