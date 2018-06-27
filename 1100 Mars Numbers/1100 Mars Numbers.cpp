#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
using namespace std;

string a[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void fun1(string s){
    int x = stoi(s);
    cout<<b[x/13];
    if((x%13) && (x/13)) cout<<" "<<a[x%13];
    else if((x%13) || (x == 0)) cout<<a[x%13];
}

void fun2(string s){
    int i = 0, t = -1;
    if(s.length() <= 4){
        for(i = 0; i < 13; i++){
            if(a[i] == s) {
                cout<<i;
                return;
            }
            if(b[i] == s){
                cout<<i*13;
                return;
            }
        }
    }
    else {
        int sum = 0;
        string temp1 = s.substr(0, 3), temp2 = s.substr(4, 3);
        for (int i = 1; i <= 12; i++) {
            if (temp1 == b[i]) sum += i * 13;
            if (temp2 == a[i]) sum += i;
        }
        cout << sum;
    }
}

int main(void){
    int n;
    string s;
    cin>>n;
    getchar();
    for(int i = 0; i < n; i++){
        getline(cin, s);
        if(isdigit(s[0])){
            fun1(s);
        }
        else 
            fun2(s);
        cout<<endl;
    }
    return 0;
}
