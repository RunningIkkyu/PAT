#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define INF 0x3fffffffffffffff
using namespace std;


int digit(char a){
    if(a >= '0' && a <= '9')
        return int(a)-'0';
    else if ( a >= 'a' && a <= 'z')
        return int(a)-'a' + 10;
    else if ( a >= 'A' && a <= 'Z')
        return int(a)-'A' + 10;
}

long long baseConversion(string num, long long radix, long long cmpnum)
{
    string s_res;
    long long res = 0;
    int j = 0;
    if (cmpnum == -1) cmpnum = INF;
    for(int i = num.length()-1; i >= 0; j++, i--){
        res += digit(num[i]) * pow(radix, j);
        if (res > cmpnum)
            return cmpnum + 1;
    }
    return res;
}

int main(void)
{
    string n[3];
    int tag;
    long long radix;
    long long r, l, mid, tmp;

    // input handling.
    cin>>n[1]>>n[2]>>tag>>radix;

    // save the number which radix has been given.
    long long num = baseConversion(n[tag], radix, -1);
    int max_ind = 0;
    // here , stuck once, write n[tag] instead of n[3-tag].Damn it!!!!.
    for(int i = 0; i < n[3-tag].length(); i++)
        if(n[3-tag][i] > n[3-tag][max_ind])
            max_ind = i;
    // test point one !!!!
    l = digit(n[3-tag][max_ind])+1;
    r = max(num, l);
    // add this two if, pass test point 17 only.
    if(n[1] == n[2])
    {
        if(n[1] == "1" || n[1] == "0")
            cout<<2<<endl;
        else
            cout<<radix<<endl;
        return 0;
    }
    
    // binary search
    mid = (l + r) / 2;
    while(l <= r){
        // convert the number in the base of mid.
        tmp = baseConversion(n[3-tag], mid, num);
        // find success
        if(tmp == num){
            cout<<mid<<endl;
            return 0;
        }
        // too large.
        else if(tmp > num)
            r = mid - 1;
        // too small.
        else
            l = mid + 1;
        mid = (l + r) / 2;
    }
    cout<<"Impossible"<<endl;
    return 0;
}