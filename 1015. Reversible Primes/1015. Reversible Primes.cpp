#include <iostream>
#include <cmath>
using namespace std;

// check if num is prime number.
bool isPrime(int num){
    int sqr = int(sqrt(num * 1.0));
    for(int i = 2; i <= sqr; i++){
        if(num % i == 0) return false;
    }
    if(num <= 1) return false;
    return true;
}

// convert to the given base, reverse and return 10 base number.
int reverse(int num, int base){
    int sum = 0;
    for(; num != 0; num /= base) sum = (sum*base) +num % base;
    return sum;
}

int main(void){
    int n, b;
    while(cin>>n, n >= 0){
        cin>>b;
        if(isPrime(n) && isPrime(reverse(n, b))) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}