#include <cstdio>
#define N 1000010
using namespace std;

int a[N];

int main(void){
    int m, n, t;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &t);
        a[t] += 1;
    }
    for(int i = 1; i < N; i++){
        if(a[i] > 0 && a[m-i] > 0){
            if((i == m - i) && (a[i] < 2)) {printf("No Solution\n"); return 0;}
            printf("%d %d\n", i, m-i);
            return 0;
        }

    }
    printf("No Solution\n");
    return 0;
}