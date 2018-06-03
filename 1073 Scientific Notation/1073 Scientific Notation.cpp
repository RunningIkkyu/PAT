#include <iostream>
#include <string>

using namespace std;


int main(void){
    string s;
    int j, int_portion, frac_portion, exp_portion;
    bool sign1, sign2;
    cin>>s;
    cout<<((s[0]=='-')?"-":"");
    for(j = 3; j < s.length(); j++) if(s[j] == 'E') break;
    exp_portion = stoi(s.substr(j+1));
    if(exp_portion < 0){
        cout<<"0.";
        for(int i = 0; i < (-exp_portion)-1 ; i++) cout<<"0";
        for(int i = 1 ; i < j; i++) if(s[i] != '.') cout<<s[i];
    }else {
        cout<<s[1];
        int cur = 3;
        while(exp_portion != 0){
            if(cur < j) cout<<s[cur++];
            else cout<<"0";
            exp_portion--;
        }
        if(cur < j)cout<<".";
        for(int i = cur; i < j; i++) cout<<s[i];
    }
    return 0;
}
