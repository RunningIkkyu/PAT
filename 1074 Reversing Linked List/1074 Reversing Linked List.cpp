#include <iostream>
#include <algorithm>
#include <vector>
#define N 100010
using namespace std;

struct Node {
    int id, data, next;
}node[N];

vector<Node> v;
vector<Node>::iterator it1;
vector<Node>::iterator it2;
int start, n, k;

void print_v(){
    for(int i = 0; i < n; i++){
        if(v[i].next != -1)
            printf("%05d %d %05d\n", v[i].id, v[i].data, v[i].next);
        else 
            printf("%05d %d %d\n", v[i].id, v[i].data, v[i].next);
    }
}

int main(void){
    scanf("%d%d%d", &start, &n, &k);
    for(int i = 0 ; i < n; i++){
        int t;
        scanf("%d", &t);
        node[t].id = t;
        scanf("%d%d", &node[t].data, &node[t].next);
    }
    Node x = node[start];
    v.push_back(x);
    while(x.next != -1){
        v.push_back(node[x.next]);
        x = node[x.next];
    }
    n = v.size();
    int remain = n;
    it1 = v.begin();
    it2 = v.begin();
    while(1){
        if(remain < k) break;
        for(int i = 0; i < k; i++){
            it2++;
            remain--;
        }
        reverse(it1, it2);
        it1=it2;
    }
    for(int i = 0; i < n-1; i++){
        v[i].next = v[i+1].id;
    }
    v[n-1].next = -1;
    print_v();
    return 0;
}
