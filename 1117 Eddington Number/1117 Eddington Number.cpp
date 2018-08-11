#include <iostream>
#include <algorithm>
#define N 100010
using namespace std;

int a[N];

int main(void){
    int n, e;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a+n, std::greater<int>());
    while(e < n && a[e] > e+1) e++;
    cout<<e<<endl;
    return 0;
}