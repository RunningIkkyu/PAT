#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 35;
typedef long long LL;
int l[MAX],r[MAX],a[MAX],ml[MAX],mr[MAX],ok;
void bu(int x,int y){
    if(abs(a[x]) >= abs(a[y])){
        if(!l[x]) l[x] = y;
        else bu(l[x],y);
    }
    else{
        if(!r[x]) r[x] = y;
        else bu(r[x],y);
    }
    return ;
}
int dfs(int x){
    if(!ok) return 0;
    if(l[x]) ml[x] += dfs(l[x]);
    if(r[x]) mr[x] += dfs(r[x]);
    if(ml[x] != mr[x]) ok = 0;
    if(a[x] < 0) return ml[x];
    else return ml[x] + 1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(l,0,sizeof l),memset(r,0,sizeof r);
        memset(ml,0,sizeof ml),memset(mr,0,sizeof mr);
        int n;
        scanf("%d",&n);
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        if(a[1] < 0) {
            puts("No");
            continue;
        }
        for(int i = 2; i <= n; i++)
            bu(1,i);
        ok = 1;
        for(int i = 1; i <= n; i++){
            if(l[i])
                if(a[i] < 0 && a[l[i]] < 0) ok = 0;
            if(r[i])
                if(a[i] < 0 && a[r[i]] < 0) ok = 0;
        }
        if(!ok) puts("No");
        else{
            dfs(1);
            if(!ok) puts("No");
            else puts("Yes");
        }
    }
    return 0;
}