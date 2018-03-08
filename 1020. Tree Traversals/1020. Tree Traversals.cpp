#include <cstdio>
#include <algorithm>
#define N 4000
using namespace std;

int level[N];
int postorder[N];
int inorder[N];
int a[N];
void pre(int index, int begin, int end, int root){
    int i;
    if(begin > end) return;
    for(i = begin; i < end && inorder[i] != postorder[root]; i++);
    level[index] = postorder[root];
    pre(2*index+1, begin, i-1, root-end-1+i);
    pre(2*index+2, i+1, end, root-1);
}

int main(void)
{
    int n, cnt = 0;
    scanf("%d", &n);
    fill(level, level+N, -1);
    for(int i = 0; i < n; i++) scanf("%d", &postorder[i]);
    for(int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    pre(0, 0, n-1, n-1);
    //for(int i = 0; level[i] != -1; i++) {
    for(int i = 0; i < N; i++) {
        if(level[i] == -1) continue;
        if(i != 0) printf(" ");
        printf("%d", level[i]);
        cnt++;
        if(cnt == n) break;
    }
    printf("\n");
    return 0;
}