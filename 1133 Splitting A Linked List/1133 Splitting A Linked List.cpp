#include <iostream>
#include <vector>
#define N 100010
using namespace std;

struct node{
    int id, value, next;
}llist[N];

vector<node> a[3];

int main(void){
    int n, id, first, k;
    cin>>first>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>id;
        llist[id].id = id;
        cin>>llist[id].value>>llist[id].next;
    }
    for(int i = first; i != -1; i = llist[i].next){
        if(llist[i].value < 0) a[0].push_back(llist[i]);
        else if(llist[i].value >= 0 && llist[i].value <= k) a[1].push_back(llist[i]);
        else a[2].push_back(llist[i]);
    }

    int flag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            if (flag == 0) {
                printf("%05d %d ", a[i][j].id, a[i][j].value);
                flag = 1;
            } else {
                printf("%05d\n%05d %d ", a[i][j].id, a[i][j].id, a[i][j].value);
            }
        }
    }
    printf("-1\n");
    return 0;
}