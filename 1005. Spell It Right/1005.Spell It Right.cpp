#include <iostream>
#include <sstream>
using namespace std;

// convert int to string.
string int2string(int n){
    stringstream ss;
    ss<<n;
    return ss.str();
}

int main(void)
{
    // define variable
    string English[10] = {
        "zero", "one", "two", "three", "four", "five",
        "six", "seven", "eight", "nine"
    };
    string n;
    int sum = 0;

    // input
    cin>>n;

    // calculate sum of all digits.
    for(int i = 0; i < n.length(); i++){
        sum += n[i]-48;
    }
    
    // convert sum to string
    n = int2string(sum);

    // output each number in english from left to right.
    for(int i = 0; i < n.length(); i++){
        if(i != 0) cout<<" ";
        cout<<English[n[i]-48];
    }
    return 0;
}