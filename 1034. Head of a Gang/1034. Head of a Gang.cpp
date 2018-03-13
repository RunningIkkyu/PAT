#include <iostream>
#include <map>
#define N 3010
using namespace std;

map<string, int> toint;
map<int, string> tostring;
map<string, int> ans;
int e[N][N], index, weight[N], visit[N];

int getind(string s){
    auto it = toint.find(s);
    int ind = (it == toint.end())? index++ : it->second;
    toint[s] = ind; tostring[ind] = s;
    return ind;
}

void dfs(int u, int &head, int &numMember, int &totalweight) {
    visit[u] = true;
    numMember++;
    if(weight[u] > weight[head])
        head = u;
    for(int v = 1; v < index; v++) {
        if(e[u][v] > 0) {
            totalweight += e[u][v];
            e[u][v] = e[v][u] = 0;
            if(visit[v] == false)
                dfs(v, head, numMember, totalweight);
        }
    }
}


int main(void){
    int n, k, w, ind1, ind2;
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        string s1, s2;
        cin>>s1>>s2>>w;
        ind1 = getind(s1);
        ind2 = getind(s2);
        weight[ind1] += w;
        weight[ind2] += w;
        e[ind1][ind2] += w;
        e[ind2][ind1] += w;
    }
    for(int i = 0; i < n; i++){
        if(visit[i] == false){
            int head = i, numMember = 0, totalweight = 0;
            dfs(i, head, numMember, totalweight);
            if(numMember > 2 && totalweight > k)
                ans[tostring[head]] = numMember;
        }//if
    }//for
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++)
        cout << it->first << " " << it->second << endl;
    return 0;
}