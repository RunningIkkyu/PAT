#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> 
using namespace std;

int N, n, m;


int calc(int n){
    int x = sqrt(double(n));
    for(int i = x; i >= 1; i--) if(n%i == 0) return i;
    return 1;
}

int main(void){
    scanf("%d", &N);
    n = calc(N);
    m = N/n;
    vector<int> a(N);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    sort(a.begin(), a.end(), greater<int>());
    vector<vector<int> > b(m, vector<int>(n));
    int level = m/2 + m%2;
    int t = 0;
    for(int i = 0; i < level; i++){
        for(int j = i; j <= n-i-1 && t <= N-1; j++) b[i][j] = a[t++];
        for(int j = i+1; j <= m-i-2 && t <= N-1; j++) b[j][n-i-1] = a[t++];
        for(int j = n-i-1; j >= i && t <= N-1; j--) b[m-i-1][j] = a[t++];
        for(int j = m-i-2; j >= i+1 && t <= N-1; j--) b[j][i] = a[t++];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d", b[i][j]);
            if(j != n-1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}