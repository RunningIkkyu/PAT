#include <iostream>
#define N 1010
using namespace std;

int n, cnt;
bool modified[N];
string a[N], b[N];

int main(void){
    cin>>n;
    for(int j = 0; j < n; j++){
        cin>>a[j]>>b[j];
        modified[j] = false;
        for(int i = 0; i < b[j].length(); i++){
            if(b[j][i] == '1'){ b[j][i] = '@'; modified[j] = true;}
            else if (b[j][i] == '0') { b[j][i] = '%';modified[j] = true;}
            else if (b[j][i] == 'l') { b[j][i] = 'L';modified[j] = true;}
            else if (b[j][i] == 'O') { b[j][i] = 'o';modified[j] = true;}
        }
        if(modified[j]) cnt++;
    }
    if(cnt == 0 && n == 1) cout<<"There is 1 account and no account is modified\n";
    else if (cnt == 0) cout<<"There are "<<n<<" accounts and no account is modified\n";
    else{
        cout<<cnt<<endl;
        for(int i = 0; i < n; i++){
            if(modified[i])
                cout<<a[i]<<" "<<b[i]<<endl;
        }

    }
    return 0;
}