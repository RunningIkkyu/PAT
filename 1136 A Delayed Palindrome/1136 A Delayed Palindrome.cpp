#include <iostream>
#include <algorithm>
using namespace std;

string add(string a){
    string b = a;
    string ans;
    reverse(b.begin(), b.end());
    int carry = 0;
    int len = a.length();
    for(int i = 0; i < len; i++){
        int num = (a[i] - '0' + b[i] - '0') + carry;
        carry = 0;
        if(num >= 10){
            carry = 1;
            num = num - 10;
        }
        ans += char(num + '0');
    }
    if(carry == 1) ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(void){
    string s;
    cin>>s;
    int i = 0;
    for(i = 0; i < 10;){
        string t = s;
        reverse(t.begin(), t.end());
        if (t == s) {
            cout << s << " is a palindromic number.";
            break;
        } else {
            cout << s << " + " << t << " = " << add(s) << endl;
            s = add(s);
            i++;
        }
    }
    if(i == 10) cout<< "Not found in 10 iterations.";
    return 0;
}