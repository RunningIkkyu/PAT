#include <iostream>
#include <algorithm>
#define N 10010

int a[N][2];
bool s[N];
using namespace std;

int main(void){
    int e, v, n, t, u; 
    cin>>v>>e;
    for(int i = 0; i < e; i++){
        cin>>a[i][0]>>a[i][1];
    }
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>t;
        fill(s, s+N, 0);
        int flag = true;
        for(int j = 0; j < t; j++){
            cin>>u;
            s[u] = true;
        }
        for(int i = 0; i < e; i++){
            if(s[a[i][0]] == false && s[a[i][1]] == false){
                flag = false;
                break;
            }
        }
        cout<<(flag == true? "Yes\n": "No\n");
    }
    return 0;
}