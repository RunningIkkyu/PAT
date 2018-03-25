#include <cstdio>
#include <vector>
#define N 1010
using namespace std;

int tree[N];
bool is_bst = true;
bool is_mirror_bst = true;
vector<int> postorder;

void bst_tranverse(int start, int end){
    int m = end + 1;
    if(is_bst == false) return;
    if(start > end) return ;
    if(start == end){
        postorder.push_back(tree[start]);
        return ;
    }
    for(int i = start + 1; i <= end; i++)
        if(tree[i] >= tree[start]) { m = i; break;}
    for(int i = m; i <= end; i++)
        if(tree[i] < tree[start]) {is_bst = false; return;}
    bst_tranverse(start+1, m-1);
    bst_tranverse(m, end);
    postorder.push_back(tree[start]);
}

void mirror_tranverse(int start, int end){
    int m = end + 1;
    if(is_mirror_bst == false) return;
    if(start > end) return ;
    if(start == end){
        postorder.push_back(tree[start]);
        return ;
    }
    for(int i = start + 1; i <= end; i++)
        if(tree[i] < tree[start]) { m = i; break;}
    for(int i = m; i <= end; i++)
        if(tree[i] >= tree[start]) {is_mirror_bst = false; return;}
    mirror_tranverse(start+1, m-1);
    mirror_tranverse(m, end);
    postorder.push_back(tree[start]);
}

int main(void){
    int n;
    bool flag;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &tree[i]);
    bst_tranverse(0, n-1);
    if(is_bst == false) {postorder.clear(); mirror_tranverse(0, n-1);}
    printf("%s\n", (flag = (is_bst || is_mirror_bst))?"YES":"NO");
    if(flag){
        for(int i = 0 ; i < postorder.size(); i++){
            if(i != 0) printf(" ");
            printf("%d", postorder[i]);
        }
    printf("\n");
    }
    return 0;
}