#include <iostream>
#include <vector>
#include <algorithm>
#define N 100010
using namespace std;

bool ishere[N];
int mate[N];
vector<int> guest;
vector<int> v;

int main(void){
    int n, p, q;
    fill(mate, mate+N, -1);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>p>>q;
        mate[p] = q;
        mate[q] = p;
    }
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>p;
        ishere[p] = true;
        guest.push_back(p);
    }
    for(int i =0; i < guest.size(); i++){
        if(mate[guest[i]] == -1 || mate[guest[i]] == guest[i] || ishere[mate[guest[i]]] == false) 
            v.push_back(guest[i]);
    }
    sort(v.begin(), v.end());
    cout<<v.size()<<endl;
    for(int i = 0; i < v.size(); i++){
        if(i != 0) printf(" ");
        printf("%05d", v[i]);
    }
    return 0;
}