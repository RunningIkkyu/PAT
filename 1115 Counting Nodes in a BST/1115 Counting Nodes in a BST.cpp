#include <iostream>
#define N 1010
#include <vector>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

Node *insertBST(Node *r, int x){
    if(r == NULL){
        r = new Node();
        r->data = x;
        r->left = r->right = NULL;
    }
    else if(x <= r->data) r->left = insertBST(r->left, x);
    else  r->right = insertBST(r->right, x);
    return r;
}

int maxdepth = -1, num[N];
void dfs(Node *r, int depth){
    if(r == NULL){
        maxdepth = max(maxdepth, depth);
        return ;
    }
    num[depth]++;
    dfs(r->left, depth+1);
    dfs(r->right, depth+1);
}

int main(void){
    int n,t;
    Node *root = NULL;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>t;
        root = insertBST(root, t);
    }
    dfs(root, 0);
    printf("%d + %d = %d\n", num[maxdepth-1], num[maxdepth-2], num[maxdepth-1] + num[maxdepth-2]);
    return 0;
}