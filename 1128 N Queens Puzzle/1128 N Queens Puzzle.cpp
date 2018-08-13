#include <iostream>
#define N 1010

using namespace std;

bool row[N];
bool viceline[2*N];
bool mainline[2*N];

int main(void){
    int m, n, t;
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>n;
        fill(row, row+N, 0);
        fill(viceline, viceline+2*N, 0);
        fill(mainline, mainline+2*n, 0);
        bool flag = false;
        for(int j = 1; j <= n; j++){
            cin>>t;
            if (flag == true) continue;
            if(row[t] == true || viceline[t+j] == true || mainline[n+t-j] == true){
                cout<<"NO"<<endl;
                flag = true;
                continue;
            }else if(j == n){cout<<"YES"<<endl;}
            else {
                row[t] = true;
                viceline[t+j] = true;
                mainline[n+t-j] = true;
            }
        }
    }
    return 0;
}
