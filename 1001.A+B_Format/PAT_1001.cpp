#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;

void format_output(long a){
    bool isnegative = (a<0?1:0);
    if (isnegative){
        cout<<"-";
        a = -a;
    }
    // string to reserve the result.
    string res;

    // convert a to string.
    stringstream ss;
    ss<<a;
    string s = ss.str();

    int j = 0;
    // remainder of length by 3
    int rem = s.length() % 3;
    // output head digits, which mounts is rem.
    for(int i = 0; i < rem; i++) cout<<s[i];
    // output remain digits and comma.
    for(int i = rem; i < s.length(); i++){
        if((i-rem)%3 == 0 && (i-rem) != 0) cout<<",";
        if((i-rem) == 0 && rem) cout<<",";
        cout<<s[i];
    }
    cout<<endl;
}

int main(void)
{
    long a, b, c;
    cin>>a>>b;
    format_output(a+b);
    return 0;
}
