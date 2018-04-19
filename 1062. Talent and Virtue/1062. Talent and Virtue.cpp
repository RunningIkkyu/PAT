#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct node{
    int id, talent, virtue;
};

vector <node> r[4];
bool compare(node a, node b){
    if(a.talent + a.virtue == b.talent + b.virtue)
        if(a.virtue == b.virtue)
            return a.id < b.id;
        else
            return a.virtue > b.virtue;
    else
        return a.talent + a.virtue > b.talent + b.virtue;
}

int main(void){
    int n, l, h, cnt = 0;
    node t;
    scanf("%d%d%d", &n, &l, &h);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &t.id, &t.virtue, &t.talent);
        if(t.talent < l || t.virtue < l) {cnt++; continue;}
        else if (t.talent >= h && t.virtue >= h) r[0].push_back(t);
        else if (t.talent < h && t.virtue >= h) r[1].push_back(t);
        else if (t.talent < h && t.virtue < h && t.talent <= t.virtue) r[2].push_back(t);
        else r[3].push_back(t);
    }
    printf("%d\n", n-cnt);
    for(int i = 0; i < 4; i++){
        sort(r[i].begin(), r[i].end(), compare);
        for(int j = 0; j < r[i].size(); j++){
            printf("%d %d %d\n", r[i][j].id, r[i][j].virtue, r[i][j].talent);
        }
    }
}