#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
const int MaxN = 100010;
int Diamonds[MaxN];
vector<pair<int, int>> Min;

int main() {

    int N, pay, start = 1, end = 0, nowD = 0, MinLost = INT32_MAX;
    bool flag = false;
    scanf("%d %d", &N, &pay);
    for (int i = 1; i <= N; ++i)scanf("%d", &Diamonds[i]);
    while (end <= N) {
        if (nowD < pay) nowD += Diamonds[++end];
        else if (nowD > pay) {
            if (nowD < MinLost) {
                MinLost = nowD;
                Min.clear();
                Min.push_back(make_pair(start, end));
            }
            else if (nowD == MinLost) Min.push_back(make_pair(start, end));
            nowD -= Diamonds[start++];
        }
        else {
            flag = true;
            printf("%d-%d\n",start,end);
            nowD += Diamonds[++end];
        }
    }

    if (!flag) {
        for (int i = 0; i < Min.size(); ++i) printf("%d-%d\n", Min[i].first,Min[i].second );
    }
    return 0;
}