#include <iostream>
#include <cmath>
#include <functional>
#include <algorithm>
#define N 100010
using namespace std;

int a[N];
int main(void){
    int n, s = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a+n, greater<int>());
    for(int i = 0; i < n/2; i++){
        s += a[i] - a[n-i-1];
    }
    if(n % 2 == 0){
        cout<<0<<" "<<s<<endl;
    }else{
        s = max(int(fabs(s-a[n/2])), int(fabs(s+a[n/2])));
        cout<<1<<" "<<s<<endl;
    }
    return 0;
}