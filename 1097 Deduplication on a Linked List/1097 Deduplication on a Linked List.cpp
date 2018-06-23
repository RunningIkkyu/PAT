#include <iostream>
#include <vector>
#include <cmath>
#define N 100010
using namespace std;

struct node{
    int id, data, next;
}list[N];
vector<node>list1;
vector<node>list2;
bool appeared[N];

int main(void){
    int start, n, tid, tdata, tnext;
    cin>>start>>n;
    for(int i = 0; i < n; i++){
        cin>>tid>>tdata>>tnext;
        node x = {tid, tdata, tnext};
        list[tid] = x;
    }
    int ind = start;
    while(ind != -1){
        tdata = abs(list[ind].data);
        if(appeared[tdata]) list2.push_back(list[ind]);
        else{
            appeared[tdata] = true;
            list1.push_back(list[ind]);
        }
        ind = list[ind].next;
    }
    for(int i = 0; i < list1.size(); i++){
        if(i == (list1.size()-1))
            printf("%05d %d -1\n", list1[i].id, list1[i].data);
        else
            printf("%05d %d %05d\n", list1[i].id, list1[i].data, list1[i+1].id);
    }
    for(int i = 0; i < list2.size(); i++){
        if(i == (list2.size()-1))
            printf("%05d %d -1\n", list2[i].id, list2[i].data);
        else
            printf("%05d %d %05d\n", list2[i].id, list2[i].data, list2[i+1].id);
    }
    return 0;
}