#include <iostream>
#define N 1000
using namespace std;


bool a[N]; 
int calsum(int u){
    int sum = 0;
    for(; u != 0; u=u/10) sum += u%10;
    return sum;
}
int main(void){
    int n,t, cnt=0;
    cin>>n;
    for(int i = 0; i < n;i++){
        cin>>t;
        int x = calsum(t);
        if(a[x] == false){
            a[x] =true;
            cnt++;
        }
    } 
    cout<<cnt<<endl;
    bool flag = false;
    for(int i = 0; i < N; i++){
        if(a[i]) {
            if(flag == true)cout<<" ";
            cout<<i;flag = true;
        }
    }
    return 0;
}

