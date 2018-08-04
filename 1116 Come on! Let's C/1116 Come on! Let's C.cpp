#include <iostream>
#define N 10010
using namespace std;

int a[N];
bool checked[N];
bool prime[N];

void FindPrime(){
    for(int i = 2; i < N; i++){
        if(prime[i] == true)
            for(int j = i+i; j < N; j += i) prime[j] = false;
    }
}


int main(void){
    fill(prime+2, prime+N, true);
    FindPrime();
    int n, t;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>t;
        a[t] = i;
    }
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>t;
        if(a[t] == 0) printf("%04d: Are you kidding?\n", t);
        else if(checked[t] == true) printf("%04d: Checked\n", t);
        else if(a[t] == 1) printf("%04d: Mystery Award\n", t);
        else if(prime[a[t]] == true) printf("%04d: Minion\n", t);
        else printf("%04d: Chocolate\n", t);
        checked[t] = true;
    }
    return 0;
}
