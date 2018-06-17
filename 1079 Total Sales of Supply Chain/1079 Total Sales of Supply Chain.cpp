#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int a[100005];
vector<int> level[100005];
int n, tn, t;
double p, r;
double dfs(int root, int lv){
    double s = 0;
    if (level[root].size() == 0){
        s += a[root] * pow(1+r/100, lv) * p;
    }
    for(int i = 0; i < level[root].size(); i++)
        s += dfs(level[root][i], lv+1);
    return s;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d%lf%lf", &n, &p, &r);
    for (int i = 0; i < n; ++i){
        scanf("%d", &tn);
        if (tn > 0){
            while (tn--){
                scanf("%d", &t);
                level[i].push_back(t);
            }
        }else{
            scanf("%d", &t);
            a[i] = t;
        }
    }
    printf("%.1f\n", dfs(0, 0));
    return 0;
}