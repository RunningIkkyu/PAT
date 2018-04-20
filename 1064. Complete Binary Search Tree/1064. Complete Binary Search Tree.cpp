#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> inorder, levelorder;

void getlevel(int start, int end, int index){
    if(start > end) return;
    int n = end - start + 1;
    int l = log(n+1) / log(2);
    int leaves = n - (pow(2, l) - 1);
    int root = start + (pow(2, l-1) - 1) + min((int)pow(2, l-1), leaves);
    levelorder[index] = inorder[root];
    getlevel(start, root-1, 2*index + 1);
    getlevel(root + 1, end, 2*index + 2);

}

int main(void){
    int n;
    scanf("%d", &n);
    inorder.resize(n);
    levelorder.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);
    sort(inorder.begin(), inorder.end());
    getlevel(0, n-1, 0);
    printf("%d", levelorder[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", levelorder[i]);
    return 0;
}