#include <iostream>
#include <algorithm>
#define N 10010
using namespace std;

string a[N];
int n;


int main(void){
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    sort(a, a + n, [](string a, string b){ return a+b < b+a; });
    string s;
    for(int i = 0; i < n; i++)
        s += a[i];
    while(s.length() != 0 && s[0] == '0')
        s.erase(s.begin());
    if(s.length() == 0) cout << 0;
    cout << s;
    return 0;
}