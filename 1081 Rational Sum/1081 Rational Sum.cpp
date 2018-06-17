#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#define MAX 110

long gcd(long a, long b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(void){
    //freopen("in.txt", "r", stdin);
    int n;
    long  a2, b2;
    long  a1 = 0, b1 = 1;          // a1/b1, a2/b2
    int gmax = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%ld/%ld", &a2, &b2);
        // fraction reduction.
        gmax = gcd(a2, b2);
        a2 /= gmax;
        b2 /= gmax;

        // reduction to a common donominator.
        gmax = gcd(b1, b2);
        a1 = (a1 * b2 + a2 * b1)/gmax;
        b1 = (b1 * b2)/gmax;
        gmax = gcd(a1, b1);
        a1 /= gmax;
        b1 /= gmax;
    }
    if(a1 % b1 == 0) printf("%ld", a1/b1);
    else{
        if(a1 > b1){
            printf("%ld %ld/%ld\n", a1/b1, a1%b1, b1);
        }
        else
            printf("%ld/%ld\n", a1, b1);
    }

    //printf("%d/%d\n", a, b);
    return 0;
}