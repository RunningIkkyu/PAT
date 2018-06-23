#include <iostream>
#define N 110
#include <vector>
using namespace std;
vector<int> v[N];
int levelcnt[N];
void dfs(int index, int depth){
    levelcnt[depth]++;
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth+1);
}
int main(void){
    int n, m, id, t, k;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        cin>>id>>k;
        for(int j = 0; j < k; j++){
            cin>>t;
            v[id].push_back(t);
        }
    }
    dfs(1, 1);
    int maxi = 0, maxn = 0;
    for(int i = 1; i < N; i++){
        if(levelcnt[i] > maxn){
            maxn = levelcnt[i];
            maxi = i;
        }
    }
    cout<<maxn<<" "<<maxi<<endl;
    return 0;
}