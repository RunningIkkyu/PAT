#include <iostream>
#include <algorithm>
#define N 110
using namespace std;

int a[N], b[N];

int main(void){
    int i, n, j; 
    cin>>n;
    for(i = 0; i < n; i++) cin>>a[i];
    for(i = 0; i < n; i++) cin>>b[i];
    for(i = 0; i < n-1 && b[i] <= b[i+1]; i++);
    for(j = i+1; j < n && b[j] == a[j]; j++);
    if(j == n){
        cout<<"Insertion Sort"<<endl;
        sort(a, a+i+2);
    }
    else{
        cout<<"Merge Sort"<<endl;
        int t = 1, flag = 1;
        while(flag){
            flag = 0;
            for(i = 0; i < n; i++) if(a[i] != b[i]) flag = 1;
            t = t * 2;
            for(i = 0; i < n/t; i++) sort(a+i*t, a+(i+1)*t);
            sort(a + n / t * t, a + n);
        }
    }
    for(i = 0; i < n; i++){
        if(i != 0) cout<<" ";
        cout<<a[i];
    }
    return 0;
}