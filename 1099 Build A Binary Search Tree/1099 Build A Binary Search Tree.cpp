#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define N 110
using namespace std;

struct TREE{
    int l, r, data;
};

int ind = 0;
vector<TREE> tree;
vector<int> v;

void inorder(int cur){
    if(tree[cur].l != -1) inorder(tree[cur].l);
    tree[cur].data = v[ind++];
    if(tree[cur].r != -1) inorder(tree[cur].r);
}

int main(void){
    int n;
    cin>>n;
    tree.resize(n);
    v.resize(n);
    for(int i = 0; i < n; i++){
        cin>>tree[i].l>>tree[i].r;
    }
    for(int i = 0; i < n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    inorder(0);
    queue<int> q;
    q.push(0);
    cout<<tree[0].data;
    while(!q.empty()){
        int ind1 = q.front(); q.pop();
        if(ind1 != 0) cout<<" "<<tree[ind1].data;
        if(tree[ind1].l != -1) q.push(tree[ind1].l);
        if(tree[ind1].r != -1) q.push(tree[ind1].r);
    }
    return 0;
}
