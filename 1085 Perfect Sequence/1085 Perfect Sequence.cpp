#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    long long n, p, t;
    //freopen("in.txt", "r", stdin);
    vector<long long> v;
    scanf("%lld%lld", &n, &p);
    for (long long i = 0; i < n; ++i){
        scanf("%lld", &t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < v.size(); ++i){
        t = p * v[i];
        int tmp = distance(v.begin(), upper_bound(v.begin(), v.end(), t)) - i;
        cnt = max(cnt, tmp);
    }
    printf("%d\n", cnt);
    return 0;
}