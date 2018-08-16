#include <iostream>
using namespace std;

int main(void){
    int n, l;
    long long int t;
    string s, s1, s2;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        l = s.length();
        s1 = s.substr(0, l/2);
        s2 = s.substr(l/2, l/2);
        t = stoi(s1) * stoi(s2);
        if(t != 0 && stoi(s)%t == 0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}